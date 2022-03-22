/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchampli <rchampli@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 13:45:29 by rchampli          #+#    #+#             */
/*   Updated: 2022/03/22 17:02:06 by rchampli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//util
char	*ft_strchr(const char *s, int c)
{
	char	*str;

	str = (char *)s;
	while (*str != c)
	{
		if (*str == '\0')
		{
			return (NULL);
		}
		str++;
	}
	return (str);
}

ssize_t	ft_istrchr(char *str, char c)
{
	char	*ch;

	ch = ft_strchr(str, c);
	if (!ch)
		return (-1);
	return ((size_t)(ch - str));
}

int	ft_strequ(char const *s1, char const *s2)
{
	int		i;

	if (s1 == NULL || s2 == NULL)
		return (0);
	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	if (s1[i] != s2[i])
		return (0);
	return (1);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*str;

	i = 0;
	str = (char *)malloc(sizeof(*s) * len + 1);
	if (!str)
		return (0);
	while (s[i])
	{
		while (i >= start && j < len)
		{
			str[i] = s[i];
			j++;
		}
		i++;
	}
	str[j] = '\0';
	return (str);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t			i;
	size_t			len;
	size_t			j;
	unsigned char	*str;

	i = 0;
	j = 0;
	len = ft_strlen(s1) + ft_strlen(s2);
	str = malloc(sizeof(char) * len + 1);
	if (!str || !s1 || !s2)
		return (0);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		str[i + j] = s2[j];
		j++;
	}
	str[i + j] = '\0';
	return ((char *)str);
}

int	ft_strstartwith(char *s1, char *s2)
{
	size_t	i;

	i = -1;
	while (s2[++i])
		if (s2[i] != s1[i])
			return (0);
	return (1);
}

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

//env

void	print_env(char **env)
{
	size_t	i;

	i = 0;
	while (env[i])
	{
		printf("%s\n", env[i]);
		i++;
	}
}

char	**realloc_env(size_t size, char **envp)
{
	char	**new;
	size_t	i;

	new = (char **)malloc(sizeof(char *) * (size + 1));
	if (!new)
		return (NULL);
	i = 0;
	while (envp[i] && i < size)
	{
		new[i] = ft_strdup(envp[i]);
		i++;
	}
	new[size] = 0;
	ft_free_array(envp);
	return (new);
}

size_t	get_env_count(char **envp)
{
	size_t	i;

	i = 0;
	while (envp[i])
		i++;
	return (i);
}

char	*get_env(char *name, char **env)
{
	size_t	i;
	char	*tmp;

	i = 0;
	while (env[i])
	{
		tmp = ft_strjoin(name, "=");
		if (ft_strstartwith(env[i], tmp))
		{
			free(tmp);
			return (ft_strchr(env[i], '=') + 1);
		}
		free(tmp);
	}
	return (NULL);
}

ssize_t	find_env(char *env, char **envp)
{
	char	*sub;
	ssize_t	i;
	ssize_t	i2;

	if (!env)
		return (0);
	i = -1;
	sub = 0;
	while (envp[++i])
	{
		i2 = ft_istrchr(envp[i], '=');
		if ((i2 == -1))
			i2 = ft_strlen(envp[i]);
		sub = ft_substr(envp[i], 0, i2);
		if (sub)
		{
			if (ft_strequ(sub, env))
			{
				free(sub);
				return (i);
			}
			free(sub);
		}
	}
	return (-1);
}

static int	modify_env(char *new_env, size_t len, ssize_t i, char **envp)
{
	char	*tmp;
	char	*new;

	tmp = ft_substr(envp[i], 0, (len + 1));
	if (!tmp)
		return (0);
	new = ft_strjoin(tmp, new_env);
	if (!new)
		return (0);
	free(envp[i]);
	free(tmp);
	envp[i] = new;
	return (1);
}

int	set_env(char *env, char *new_env, char **envp)
{
	char	*tmp;
	ssize_t	i;
	size_t	len;

	if (!env || !new_env)
		return (0);
	len = ft_strlen(env);
	i = find_env(env, envp);
	if (i != -1)
		return (modify_env(new_env, len, i, envp));
	else
	{
		len = get_env_count(envp) + 1;
		envp = realloc_env(len, envp);
		tmp = ft_strjoin(env, '=');
		envp[len - 1] = ft_strjoin(tmp, new_env);
		free(tmp);
		return (1);
	}
	return (0);
}
