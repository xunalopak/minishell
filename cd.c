/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchampli <rchampli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 15:10:06 by rchampli          #+#    #+#             */
/*   Updated: 2022/03/22 23:05:16 by rchampli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	change(char *path, int home)
{
	char	*pwd;

	pwd = getcwd(NULL, 0);
	if (!chdir(path))
	{
		if (pwd)
		{
			set_env("OLDPWD", pwd);
			free(pwd);
		}
		pwd = getcwd(NULL, 0);
		if (pwd)
		{
			set_env("PWD", pwd);
			free(pwd);
		}
		if (home)
			free(path);
		return (1);
	}
	free(pwd);
	return (0);
}

int	set_directory(char *path, int home)
{
	struct stat	st;

	if (change(path, home))
		return (1);
	dup2(STDOUT_FILENO, STDERR_FILENO);
	printf("minishell: cd: ");
	printf("%s", path);
	if (stat(path, &st) == -1)
		printf(": No such file or directory");
	else if (!(st.st_mode & S_IXUSR))
		printf(": Permission denied");
	else
		printf(": Not a directory");
	printf("\n");
	if (home)
		free(path);
	return (1);
}

int	s_path(char **av)
{
	char	*tmp;

	if (ft_strequ(av[1], "-"))
	{
		tmp = get_env("OLDPWD");
		if (tmp)
		{
			set_directory(tmp, 0);
			free(tmp);
		}
		tmp = get_env("PWD");
		if (tmp)
		{
			printf("%s", tmp);
			free(tmp);
		}
		return (1);
	}
	return (set_directory(av[1], 0));
}

int	cd(char **av)
{
	char	*home;

	home = NULL;
	if (av && av[1] && av[2])
	{
		dup2(STDOUT_FILENO, STDERR_FILENO);
		printf("minishell: cd: too many arguments\n");
		return (1);
	}
	if (!av || ft_strequ(av, "~") || ft_strequ(av, "--"))
	{
		home = get_env("HOME");
		if (!home)
		{
			dup2(STDOUT_FILENO, STDERR_FILENO);
			printf("minishell: cd: HOME not set\n");
			return (1);
		}
		return (set_directory(home, 1));
	}
	av[1] = add_home_path(av[1]);
	return (s_path(av));
}
