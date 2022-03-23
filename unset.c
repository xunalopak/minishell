/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchampli <rchampli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 16:41:24 by rchampli          #+#    #+#             */
/*   Updated: 2022/03/23 15:33:09 by rchampli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

static char	**remove_env(ssize_t i2, char **envp)
{
	char	*tmp;
	size_t	i;
	size_t	size;

	i = i2;
	size = get_env_count(envp);
	while (envp[i + 1])
	{
		tmp = ft_strdup(envp[i + 1]);
		free(envp[i]);
		envp[i] = tmp;
		i++;
	}
	return (realloc_env((size - 1), envp, 1));
}

int	unset(char **arg, char ***envp)
{
	size_t	i;
	ssize_t	i2;

	if (!arg[1])
		return (1);
	i = 0;
	while (arg[++i])
	{
		i2 = find_env(arg[i], *envp);
		if (i2 != -1)
		{
			if (*envp[i])
				*envp = remove_env(i2, *envp);
		}
		else
		{
			dup2(STDOUT_FILENO, STDERR_FILENO);
			printf("minishell: unset `%s': not a valid identifier\n", arg[i]);
		}
	}
	return (1);
}

int	main(int ac, char **av, char **envp)
{
	char **env;
	env = realloc_env(get_env_count(envp), envp, 0);
	ft_export(av, &env);
	print_env(env);
}
