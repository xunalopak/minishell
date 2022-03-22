/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchampli <rchampli@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 16:41:24 by rchampli          #+#    #+#             */
/*   Updated: 2022/03/22 18:15:02 by rchampli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	**remove_env(ssize_t i2, char **envp)
{
	char	*tmp;
	size_t	i;
	size_t	size;

	i = i2;
	size = get_envs_count();
	while (envp[i + 1])
	{
		tmp = ft_strdup(envp[i + 1]);
		free(envp[i]);
		envp[i] = tmp;
		i++;
	}
	return (realloc_env((size - 1)));
}

int	unset(char **arg, char **envp)
{
	size_t	i;
	ssize_t	i2;
	
	if (!arg[1])
		return (1);
	i = 0;
	while (arg[++i])
	{
		i2 = find_env(arg[i]);
		if (i2 != -1)
		{
			if (envp[i])
				envp[i] = remove_env(i2, envp);
		}
		else
			printf("minishell: unset `%s': not a valid identifier\n",arg[i]);
	}
	return (1);
}