/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchampli <rchampli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 01:54:59 by rchampli          #+#    #+#             */
/*   Updated: 2022/03/23 15:44:37 by rchampli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	size_t			i;
	char			*str;

	i = 0;
	if (!s)
		return (0);
	if (ft_strlen(s) < start)
	{
		return (ft_strdup(""));
	}
	if (ft_strlen(&s[start]) <= len)
		len = ft_strlen(&s[start]);
	str = malloc((sizeof(char) * (len + 1)));
	if (!str)
		return (0);
	while (i < len)
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
