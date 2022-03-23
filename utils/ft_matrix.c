/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrix.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchampli <rchampli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 01:18:51 by rchampli          #+#    #+#             */
/*   Updated: 2022/03/23 14:49:17 by rchampli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_matrixlen(char **m)
{
	int	i;

	i = 0;
	while (m && m[i])
		i++;
	return (i);
}

void	ft_free_matrix(char ***m)
{
	int	i;

	i = 0;
	while (m[0][i])
	{
		free(m[0][i]);
		i++;
	}
	free(m[0]);
	m = NULL;
}

void	ft_extend_matrix2(char **in, char *newstr, char **out, int i)
{
	out[i] = ft_strdup(in[i]);
	if (!out[i])
	{
		ft_free_matrix(&in);
		ft_free_matrix(&out);
	}
}

char	**ft_extend_matrix(char **in, char *newstr)
{
	char	**out;
	int		len;
	int		i;

	i = -1;
	out = NULL;
	if (!newstr)
		return (in);
	len = ft_matrixlen(in);
	out = malloc(sizeof(char *) * (len + 2));
	if (!out)
		return (in);
	out[len + 1] = NULL;
	while (++i < len)
		ft_extend_matrix2(in, newstr, out, i);
	out[i] = ft_strdup(newstr);
	if (!out)
		return (0);
	ft_free_matrix(&in);
	return (out);
}
