/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchampli <rchampli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 13:45:58 by rchampli          #+#    #+#             */
/*   Updated: 2022/03/23 15:42:27 by rchampli         ###   ########.fr       */
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

//signal
void		sigint_handler(int sign_num, pid_t pid);

//exit
void		ft_exit(void);

//is_a_builtin
int			is_a_builtin(char *arg);

//pwd
int			pwd(void);

//echo
int			echo(char **av, char **envp);

//env
size_t		get_env_count(char **envp);
int			set_env(char *env, char *new_env, char **envp);
char		**realloc_env(size_t size, char **envp, int to_free);
ssize_t		find_env(char *env, char **envp);
int			print_env(char **env);
char		*get_env(char *name, char **env);

//cd
int			cd(char **av, char **envp);

//export
char		**dup_env(char **envp);
int			ft_export(char **av, char ***envp);
static void	print_export(char **export);
void		sort_env(char **envp);
static void	add(char **av, size_t i, char ***envp);
static void	modify(char **av, char *st, size_t i, char ***envp);
static int	set(char *av, size_t equ, size_t index, char **envp);
int			check_export_name(char *av);
static int	sub_free(char *st, char *end, char **envp);

//unset
int			unset(char **arg, char ***envp);

//utils
int			ft_stlen(char *s);
int			ft_isalpha(int c);
int			ft_isdigit(int c);
int			ft_matrixlen(char **m);
int			ft_strlen(char *s);
int			ft_strcmp(char *s1, char *s2);
int			ft_strchr_i( char *s, int c);
int			ft_strstartwith(char *s1, char *s2);
int			ft_strequ(char *s1, char *s2);
int			ft_strncmp(char *s1, char *s2, size_t n);
char		*ft_strdup(char *s);
char		*ft_strchr(char *s, int c);
char		*ft_strjoin(char *s1, char *s2);
char		**ft_extend_matrix(char **in, char *newstr);
char		*ft_substr(char *s, unsigned int start, size_t len);
ssize_t		ft_istrchr(char *str, char c);
void		ft_free_matrix(char ***m);
void		ft_free_array(char **array);

#endif
