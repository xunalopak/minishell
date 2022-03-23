/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchampli <rchampli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 13:07:26 by rchampli          #+#    #+#             */
/*   Updated: 2022/03/23 02:04:22 by rchampli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	sub_free(char *st, char *end, char **envp)
{
	if (set_env(st, end, envp))
	{
		free(st);
		free(end);
		return (0);
	}
	free(st);
	free(end);
	return (1);
}

static int	set(char *av, size_t equ, size_t index, char **envp)
{
	char	*st;
	char	*end;
	ssize_t	equ_env;

	if (equ == ft_strlen(av))
		return (0);
	equ_env = ft_istrchr(envp[index], '=');
	if (equ_env == -1)
	{
		equ_env = ft_strlen(envp[index]);
		st = envp[index];
		envp[index] = ft_strjoin(envp[index], "=");
		if (!envp)
			return (0);
		free(st);
	}
	st = ft_substr(envp[index], 0, (size_t)equ_env);
	if (!st)
		return (0);
	end = ft_substr(av, (equ + 1), ft_strlen(av));
	if (!end)
		return (0);
	return (sub_free(st, end, envp));
}

static void	modify(char **av, char *st, size_t i, char ***envp)
{
	char	*end;
	size_t	count;

	end = NULL;
	count = get_env_count(*envp) + 1;
	*envp = realloc_env(count, *envp, 1);
	st = ft_substr(av[i], 0, ft_istrchr(av[i], '=') + 1);
	if (!st)
		return ;
	end = ft_substr(av[i], ft_istrchr(av[i], '=') + 1, ft_strlen(av[i]));
	if (!end)
	{
		free(st);
		return ;
	}
	(*envp)[count - 1] = ft_strjoin(st, end);
	free(st);
	free(end);
}

static void	add(char **av, size_t i, char ***envp)
{
	ssize_t	index;
	size_t	equal_index;
	char	*st;

	equal_index = ft_istrchr(av[i], '=');
	if (equal_index == (size_t) - 1)
		equal_index = ft_strlen(av[i]);
	st = ft_substr(av[i], 0, equal_index);
	index = find_env(st, *envp);
	free(st);
	if (index != -1)
		set(av[i], equal_index, index, *envp);
	else
		modify(av, st, i, envp);
}

int	export(char **av, char ***envp)
{
	size_t	i;

	if (!av[1])
	{
		sort_env(*envp);
		return (1);
	}
	i = 0;
	while (av[++i])
	{
		if (!check_export_name(av[i]))
		{
			dup2(STDOUT_FILENO, STDERR_FILENO);
			printf("minishell: export: `%s': not a valid identifier\n",
				av[i]);
			continue ;
		}
		add(av, i, envp);
	}
	return (1);
}
