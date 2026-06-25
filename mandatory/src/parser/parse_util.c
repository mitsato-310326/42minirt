/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keitotak <keitotak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 17:36:52 by keitotak          #+#    #+#             */
/*   Updated: 2026/06/25 15:42:01 by keitotak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	*ft_realloc(void *p, size_t size)
{
	void	*mem;
	char	*str;

	str = (char *)p;
	if (ft_strlen(str) + 1 >= size)
		return (p);
	mem = malloc(size);
	if (mem == NULL)
		return (NULL);
	ft_strlcpy((char *)mem, str, size);
	free(p);
	return (mem);
}

char	*ft_strndup(char *str, size_t n)
{
	char	*dup;
	size_t	i;

	dup = (char *)malloc(sizeof(char) * (n + 1));
	if (dup == NULL)
		return (NULL);
	i = 0;
	while (str[i] && i < n)
	{
		dup[i] = str[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

void	free_array(char **array, size_t size)
{
	while (size--)
		free(array[size]);
	free(array);
}
