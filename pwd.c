/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchampli <rchampli@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 14:06:52 by rchampli          #+#    #+#             */
/*   Updated: 2022/03/22 17:02:21 by rchampli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int	pwd(void)
{
	char	*dir;

	dir = getcwd((char *) NULL, 1);
	printf("%s\n", dir);
	free(dir);
	if (dir == NULL)
		return (EXIT_SUCCESS);
	else
		return (EXIT_FAILURE);
}
