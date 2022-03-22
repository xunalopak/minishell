/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_a_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchampli <rchampli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 22:29:00 by rchampli          #+#    #+#             */
/*   Updated: 2022/03/22 22:48:21 by rchampli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_strequ(char const *s1, char const *s2)
{
	int		i;

	if (s1 == NULL || s2 == NULL)
		return (0);
	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	if (s1[i] != s2[i])
		return (0);
	return (1);
}

int	is_a_builtin(char **av)
{
	char	*arg;

	arg = av[1];
	if (ft_strequ(arg, "cd"))
		return (0);
	else if (ft_strequ(arg, "export"))
		return (0);
	else if (ft_strequ(arg, "pwd"))
		return (0);
	else if (ft_strequ(arg, "unset"))
		return (0);
	else if (ft_strequ(arg, "env"))
		return (0);
	else if (ft_strequ(arg, "echo"))
		return (0);
	return (1);
}

void	launch_builtin(char *prgm, char **av, char ***envp)
{
	// reallouer toute la table envp
}

int	main(int ac, char **av, char **envp)
{
	printf("%i", is_a_builtin(av));
}