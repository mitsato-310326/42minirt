/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitsato <mitsato@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 11:10:33 by mitsato           #+#    #+#             */
/*   Updated: 2025/10/18 19:44:49 by mitsato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strsizedup(char const *str, int size)
{
	int		i;
	char	*dst;

	i = 0;
	dst = malloc((size + 1) * sizeof(char));
	if (!dst)
		return (NULL);
	while (size > i)
	{
		dst[i] = str[i];
		++i;
	}
	dst[i] = '\0';
	return (dst);
}

static int	size_split(char const *str, char split)
{
	int	t;
	int	count;
	int	len;

	t = 0;
	count = 0;
	while (*str && *str == split)
		++str;
	len = ft_strlen(str);
	while (t < len)
	{
		while (!(str[t] == '\0' || str[t] == split) && t < len)
			++t;
		++count;
		while (t < len && (str[t] == split))
			++t;
	}
	return (count);
}

static char	**ft_freeall(char **mono, int size)
{
	while (--size >= 0)
		free(mono[size]);
	free(mono);
	return (NULL);
}

static void	set_param(int *n, int *len, int *i, int strlen)
{
	*n = 0;
	*len = strlen;
	*i = strlen;
}

char	**ft_split(char const *s, char c)
{
	char	**mono;
	int		i;
	int		n;
	int		len;

	mono = malloc((size_split(s, c) + 1) * sizeof(char *));
	if (!mono)
		return (NULL);
	while ((*s == c) && *s)
		++s;
	set_param(&n, &len, &i, ft_strlen(s));
	while (*s)
	{
		while (!(s[len - i] == '\0' || s[len - i] == c) && i > 0)
			--i;
		mono[n] = ft_strsizedup(s, len - i);
		if (!mono[n++])
			return (ft_freeall(mono, n - 1));
		s += len - i;
		len = i;
		while ((*s == c) && *s)
			++s;
	}
	mono[n] = NULL;
	return (mono);
}

// int	main(void)
// {
// 	char	**mono;
// 	mono = ft_split("fea---feae-efaw-", '-');
// 	while (*mono)
// 		printf("%s\n", *(mono++));
// }
