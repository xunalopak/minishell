/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchampli <rchampli@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 13:07:26 by rchampli          #+#    #+#             */
/*   Updated: 2022/03/15 11:49:44 by rchampli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
	dest = malloc(sizeof(char) * ft_strlen(s));
	if (!dest)
		return (0);
	while (s[i])
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
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
	out[len + 1] = NULL;
	if (!out)
		return (in);
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
	pos = ft_strchr_i(av, '=');
	if (pos == -1)
		return (-1);
	while (envp[i[1]])
	{
		if (!ft_strncmp(envp[i[1]], av, pos + 1))
			return (1);
		i[1]++;
	}
	return (0);
}

//av doit etre remplacé par le contenu du prompt
//dans la structure remplacé le envp par la place de l'envp
int	export(char **envp)
{
	int		ij[2];
	int		pos;
	char	**argv;

	argv = envp;
	if (ft_matrixlen(argv) >= 2)
	{
		ij[0] = 1;
		while (argv[ij[0]])
		{
			pos = var_in_envp(argv[ij[0]], envp, ij);
			if (pos == 1)
			{
				free(envp[ij[1]]);
				envp[ij[1]] = ft_strdup(argv[ij[0]]);
			}
			else if (!pos)
				envp = ft_extend_matrix(envp, argv[ij[0]]);
			ij[0]++;
		}
	}
	return (0);
}

int	main(int ac, char **av, char **envp)
{
	export_env(av, envp);
}
