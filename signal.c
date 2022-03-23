/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchampli <rchampli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 03:26:50 by rchampli          #+#    #+#             */
/*   Updated: 2022/03/23 17:35:41 by rchampli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
//signal(SIGINT, sigint_handler);

// peut etre recuper le pid sur un fork dans l'execution
void	sigint_handler(int sign_num)
{
	if (sign_num == SIGINT)
		// control+c
	else if (sign_num == SIGQUIT)
		/* control+\ */
}

