/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchampli <rchampli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 01:16:37 by rchampli          #+#    #+#             */
/*   Updated: 2022/03/23 14:43:22 by rchampli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*ft_strdup( char *s)
{
	unsigned int	i;
	unsigned char	*dest;

	i = 0;
	dest = malloc(sizeof(char *) * ft_strlen(s));
	if (!dest)
		return (0);
	while (s[i])
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return ((char *)dest);
}
