/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keitotak <keitotak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 21:41:31 by keitotak          #+#    #+#             */
/*   Updated: 2026/06/26 23:39:44 by keitotak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static char	**free_arr(char **arr)
{
	while (*arr)
		free(*arr++);
	free(arr);
	return (NULL);
}

static size_t	word_count(char const *s, char const *set)
{
	size_t	cnt;
	int		flg;

	cnt = 0;
	flg = 1;
	while (*s)
	{
		if (ft_strchr(set, *s))
			flg = 1;
		else
		{
			if (flg == 1)
				cnt++;
			flg = 0;
		}
		s++;
	}
	return (cnt);
}

char	**my_split(char const *s, char const *set)
{
	char	**arr;
	size_t	cnt;
	size_t	len;
	size_t	i;

	cnt = word_count(s, set);
	arr = (char **)ft_calloc(cnt + 1, sizeof(char *));
	if (arr == NULL)
		return (NULL);
	i = 0;
	while (*s && i < cnt)
	{
		while (*s && ft_strchr(set, *s))
			s++;
		len = 0;
		while (s[len] && !ft_strchr(set, s[len]))
			len++;
		arr[i] = ft_substr(s, 0, len);
		if (arr[i] == NULL)
			return (free_arr(arr));
		s += len;
		i++;
	}
	return (arr);
}
