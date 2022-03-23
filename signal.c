/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchampli <rchampli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 03:26:50 by rchampli          #+#    #+#             */
/*   Updated: 2022/03/23 17:34:02 by rchampli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
//signal(SIGINT, sigint_handler);

// peut etre recuper le pid sur un fork dans l'execution
void	sigint_handler(int sign_num)
{
	if (sign_num == SIGINT)
		printf("\n");
		// control+c
	else if (sign_num == SIGQUIT)
		printf("\b\b  \b\b");
		/* control+\ */
}

