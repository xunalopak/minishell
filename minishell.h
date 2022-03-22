/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchampli <rchampli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 13:45:58 by rchampli          #+#    #+#             */
/*   Updated: 2022/03/23 00:36:51 by rchampli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <signal.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <errno.h>


//env
size_t	get_env_count(char **envp);
int		set_env(char *env, char *new_env, char **envp);
char	**realloc_env(size_t size, char **envp, int	to_free);
ssize_t	find_env(char *env, char **envp);
void	print_env(char **env);
//utils
char	*ft_strchr(const char *s, int c);
ssize_t	ft_istrchr(char *str, char c);
int		ft_strequ(char const *s1, char const *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
void	ft_free_array(char **array);
int		ft_strcmp(char *s1, char *s2);
int		ft_strlen(const char *s);
char	*ft_strdup(const char *s);

#endif
