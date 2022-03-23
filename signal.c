/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchampli <rchampli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 03:26:50 by rchampli          #+#    #+#             */
/*   Updated: 2022/03/23 13:34:00 by rchampli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
//signal(SIGINT, sigint_handler);

void	process(int sign_num, pid_t pid)
{
	if (!kill(pid, sign_num))
	{
		if (sign_num == SIGQUIT)
			printf("Quit: 3\n");
		else if (sign_num == SIGINT)
			printf("\n");
	}
	else if (sign_num == SIGINT)
		printf("\n");
}

// peut etre recuper le pid sur un fork dans l'execution
void	sigint_handler(int sign_num, pid_t pid)
{
	if ((sign_num == SIGINT || sign_num == SIGQUIT) && pid != 0)
		process(sign_num, pid);
	else
	{
		if (sign_num == SIGINT)
			printf("\n");
		else if (sign_num == SIGQUIT)
			printf("\b\b  \b\b");
	}
}
