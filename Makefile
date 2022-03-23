# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rchampli <rchampli@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/23 16:07:19 by rchampli          #+#    #+#              #
#    Updated: 2022/03/23 16:23:18 by rchampli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= minishell

cc		= gcc

CFLAGS	= -Wall -Wextra -Werror

SRCS	= *.c */*.c

all: $(NAME)

OBJS	= $(SRCS:.c=.o)

$(NAME)	: $(OBJS) minishell.h
	@$(CC) $(OBJS) -o $(NAME)
	@echo "\033[1;35m
	$$\      $$\ $$$$$$\ $$\   $$\ $$$$$$\  $$$$$$\  $$\   $$\ $$$$$$$$\ $$\       $$\        \n
	$$$\    $$$ |\_$$  _|$$$\  $$ |\_$$  _|$$  __$$\ $$ |  $$ |$$  _____|$$ |      $$ |       \n
	$$$$\  $$$$ |  $$ |  $$$$\ $$ |  $$ |  $$ /  \__|$$ |  $$ |$$ |      $$ |      $$ |       \n
	$$\$$\$$ $$ |  $$ |  $$ $$\$$ |  $$ |  \$$$$$$\  $$$$$$$$ |$$$$$\    $$ |      $$ |       \n
	$$ \$$$  $$ |  $$ |  $$ \$$$$ |  $$ |   \____$$\ $$  __$$ |$$  __|   $$ |      $$ |       \n
	$$ |\$  /$$ |  $$ |  $$ |\$$$ |  $$ |  $$\   $$ |$$ |  $$ |$$ |      $$ |      $$ |       \n
	$$ | \_/ $$ |$$$$$$\ $$ | \$$ |$$$$$$\ \$$$$$$  |$$ |  $$ |$$$$$$$$\ $$$$$$$$\ $$$$$$$$\  \n 
	\__|     \__|\______|\__|  \__|\______| \______/ \__|  \__|\________|\________|\________| \n
																							\033[0m"
%.o:%.c
	@$(CC) $(CFLAGS) -c $^ -o $@

clean:
	@rm -f $(OBJS)
	
fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: re all fclean clean