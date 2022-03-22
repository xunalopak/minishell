/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchampli <rchampli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 13:07:26 by rchampli          #+#    #+#             */
/*   Updated: 2022/03/23 00:56:15 by rchampli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_isalpha(int c)
{
	return ((c >= 65 && c <= 90) || (c >= 97 && c <= 122));
}

int	ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}

int	ft_isdigit(int c)
{
	return (c >= 48 && c <= 57);
}

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] && s2[i] && i < n)
		i++;
	if (i <= n)
		return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	return (0);
}

char	*ft_strdup(const char *s)
{
	unsigned int	i;
	unsigned char	*dest;

	i = 0;
	dest = malloc(sizeof(char *) * ft_strlen(s));
	if (!dest)
		return (0);
	while (s[i])
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return ((char *)dest);
}

int	ft_strchr_i(const char *s, int c)
{
	unsigned char	c_unsigned;
	int				i;

	i = 0;
	if (!s)
		return (-1);
	c_unsigned = (unsigned char)c;
	while (s[i] != '\0')
	{
		if (s[i] == c_unsigned)
			return (i);
		i++;
	}
	if (c_unsigned == '\0')
		return (i);
	return (-1);
}

int	ft_matrixlen(char **m)
{
	int	i;

	i = 0;
	while (m && m[i])
		i++;
	return (i);
}

void	ft_free_matrix(char ***m)
{
	int	i;

	i = 0;
	while (m[0][i])
	{
		free(m[0][i]);
		i++;
	}
	free(m[0]);
	m = NULL;
}

char	**ft_extend_matrix(char **in, char *newstr)
{
	char	**out;
	int		len;
	int		i;

	i = -1;
	out = NULL;
	if (!newstr)
		return (in);
	len = ft_matrixlen(in);
	out = malloc(sizeof(char *) * (len + 2));
	if (!out)
		return (in);
	out[len + 1] = NULL;
	while (++i < len)
	{
		out[i] = ft_strdup(in[i]);
		if (!out[i])
		{
			ft_free_matrix(&in);
			ft_free_matrix(&out);
		}
	}
	out[i] = ft_strdup(newstr);
	ft_free_matrix(&in);
	return (out);
}

static int	var_in_envp(char **av, char **envp, int i[2])
{
	int	pos;

	i[1] = 0;
	pos = ft_strchr_i(av[1], '=');
	if (pos == -1)
		return (-1);
	while (envp[i[1]])
	{
		if (!ft_strncmp(envp[i[1]], av[1], pos + 1))
			return (1);
		i[1]++;
	}
	return (0);
}

//av doit etre remplacé par le contenu du prompt
//dans la structure remplacé le envp par la place de l'envp
static char	**dup_env(char **envp)
{
	char	**dup;
	size_t	count;

	count = get_env_count(envp);
	dup = (char **)malloc(sizeof(char *) * (count + 1));
	if (!dup)
		return (NULL);
	dup[count] = 0;
	count--;
	while (count != (unsigned long)-1)
	{
		dup[count] = ft_strdup(envp[count]);
		count--;
	}
	return (dup);
}

static void	print_export(char **export)
{
	size_t	i;
	size_t	j;
	char	equ;

	i = 0;
	while (export[i])
	{
		equ = 1;
		j = 0;
		printf("declare -x ");
		while (export[i][j])
		{
			printf("%c", export[i][j]);
			if (export[i][j] == '=' && equ)
			{
				printf("%c", 34);
				equ--;
			}
			j++;
		}
		if (!equ)
			printf("%c", 34);
		printf("\n");
		i++;
	}
}

void	sort_env(char **envp)
{
	char	**dup;
	char	*tmp;
	size_t	i;
	size_t	j;

	dup = dup_env(envp);
	i = 0;
	while (dup[i])
	{
		j = i + 1;
		while (dup[j])
		{
			if (ft_strcmp(dup[i], dup[j]) > 0)
			{
				tmp = dup[i];
				dup[i] = dup[j];
				dup[j] = tmp;
			}
			j++;
		}
		i++;
	}
	print_export(dup);
	ft_free_array(dup);
}

int	check_export_name(char *av)
{
	size_t	i;
	char	alpha;

	i = 0;
	alpha = 0;
	if (!av || !av[0] || av[0] == '=')
		return (0);
	while (av[i] && av[i] != '=')
	{
		if (ft_isalpha(av[i]))
			alpha = 1;
		else
		{
			if (ft_isdigit(av[i]) && !alpha)
				return (0);
			else if (!ft_isdigit(av[i]) && av[i] != '_')
				return (0);
		}
		i++;
	}
	return (1);
}

static int	sub_free(char *st, char *end, char **envp)
{
	if (set_env(st, end, envp))
	{
		free(st);
		free(end);
		return (0);
	}
	free(st);
	free(end);
	return (1);
}

static int	set(char *av, size_t equ, size_t index, char **envp)
{
	char	*st;
	char	*end;
	ssize_t	equ_env;

	if (equ == ft_strlen(av))
		return (0);
	equ_env = ft_istrchr(envp[index], '=');
	if (equ_env == -1)
	{
		equ_env = ft_strlen(envp[index]);
		st = envp[index];
		envp[index] = ft_strjoin(envp[index], "=");
		if (!envp)
			return (0);
		free(st);
	}
	st = ft_substr(envp[index], 0, (size_t)equ_env);
	if (!st)
		return (0);
	end = ft_substr(av, (equ + 1), ft_strlen(av));
	if (!end)
		return (0);
	return (sub_free(st, end, envp));
}

static void	modify(char **av, char *st, size_t i, char ***envp)
{
	char	*end;
	size_t	count;

	end = NULL;
	count = get_env_count(*envp) + 1;
	*envp = realloc_env(count, *envp, 1);
	st = ft_substr(av[i], 0, ft_istrchr(av[i], '=') + 1);
	if (!st)
		return ;
	end = ft_substr(av[i], ft_istrchr(av[i], '=') + 1, ft_strlen(av[i]));
	if (!end)
	{
		free(st);
		return ;
	}
	(*envp)[count - 1] = ft_strjoin(st, end);
	free(st);
	free(end);
}

static void	add(char **av, size_t i, char ***envp)
{
	ssize_t	index;
	size_t	equal_index;
	char	*st;

	equal_index = ft_istrchr(av[i], '=');
	if (equal_index == (size_t) - 1)
		equal_index = ft_strlen(av[i]);
	st = ft_substr(av[i], 0, equal_index);
	index = find_env(st, *envp);
	free(st);
	if (index != -1)
		set(av[i], equal_index, index, *envp);
	else
		modify(av, st, i, envp);
}

int	export(char **av, char ***envp)
{
	size_t	i;

	if (!av[1])
	{
		sort_env(*envp);
		return (1);
	}
	i = 0;
	while (av[++i])
	{
		if (!check_export_name(av[i]))
		{
			dup2(STDOUT_FILENO, STDERR_FILENO);
			printf("minishell: export: `%s': not a valid identifier\n",
				av[i]);
			continue ;
		}
		add(av, i, envp);

	}
	return (1);
}
