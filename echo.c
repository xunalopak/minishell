/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchampli <rchampli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 18:27:10 by rchampli          #+#    #+#             */
/*   Updated: 2022/03/23 14:45:43 by rchampli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static size_t	check_n(char **av)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (av[++i])
	{
		j = 0;
		if (av[i][j++] == '-' && av[i][j] && av[i][j] == 'n')
		{
			while (av[i][j] == 'n')
				j++;
			if (av[i][j] && av[i][j] != 'n')
				return (1);
		}
		else
			return (i);
	}
	return (i);
}

int	echo(char **av, char **envp)
{
	size_t	i;
	int		n;

	n = 1;
	if (!av[1])
	{
		printf("\n");
		return (1);
	}
	if ((ft_strequ(av[1], " ") && !av[2]))
		return (1);
	i = check_n(av);
	if (i > 1)
		n = 0;
	while (av[i])
	{
		printf("%s", av[i]);
		i++;
		if (av[i])
			printf(" ");
	}
	if (n)
		printf("\n");
	return (1);
}
