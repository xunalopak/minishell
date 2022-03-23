/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstartwith.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchampli <rchampli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 01:53:35 by rchampli          #+#    #+#             */
/*   Updated: 2022/03/23 01:54:32 by rchampli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_strstartwith(char *s1, char *s2)
{
	size_t	i;

	i = -1;
	while (s2[++i])
		if (s2[i] != s1[i])
			return (0);
	return (1);
}
