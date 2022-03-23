/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_istrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchampli <rchampli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 01:56:32 by rchampli          #+#    #+#             */
/*   Updated: 2022/03/23 14:36:08 by rchampli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

ssize_t	ft_istrchr(char *str, char c)
{
	char	*ch;

	ch = ft_strchr(str, c);
	if (!ch)
		return (-1);
	return ((size_t)(ch - str));
}
