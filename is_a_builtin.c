/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_a_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchampli <rchampli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 22:29:00 by rchampli          #+#    #+#             */
/*   Updated: 2022/03/23 02:04:39 by rchampli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
