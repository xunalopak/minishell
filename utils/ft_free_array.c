/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_array.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchampli <rchampli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 01:52:22 by rchampli          #+#    #+#             */
/*   Updated: 2022/03/23 14:36:15 by rchampli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_free_array(char **array)
{
	size_t	i;

	i = -1;
	if (!array)
		return ;
	while (array[++i] != NULL)
	{
		free(array[i]);
	}
	free(array);
}
