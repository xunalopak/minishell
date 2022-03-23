/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_a_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchampli <rchampli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 22:29:00 by rchampli          #+#    #+#             */
/*   Updated: 2022/03/23 02:17:08 by rchampli         ###   ########.fr       */
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

int	launch_builtin(char *prgm, char **av, char ***envp)
{
	char	*arg;
	int		i;

	i = 1;
	arg = av[1];
	if (ft_strequ(arg, "cd"))
		i = cd(av, &envp);
	else if (ft_strequ(arg, "export"))
		i = export(av, &envp);
	else if (ft_strequ(arg, "pwd"))
		i = pwd();
	else if (ft_strequ(arg, "unset"))
		i = unset(av, &envp);
	else if (ft_strequ(arg, "env"))
		i = print_env(&envp);
	else if (ft_strequ(arg, "echo"))
		i = echo(av, &envp);
	return (i);
}
