/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keitotak <keitotak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 09:38:48 by keitotak          #+#    #+#             */
/*   Updated: 2026/06/23 13:33:15 by keitotak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#define BUFSIZE 1024

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

char	*read_str(char *file)
{
	int		fd;
	int		read_count;
	char	buf[BUFSIZE + 1];
	char	*str;

	fd = open(file, O_RDONLY);
	read_count = 1;
	str = malloc(1);
	str[0] = 0;
	while (read_count != 0)
	{
		read_count = read(fd, buf, BUFSIZE);
		if (read_count < 0)
			return (free(str), NULL);
		str = ft_realloc(str, ft_strlen(str) + read_count + 1);
		if (str == NULL)
			return (free(str), NULL);
		ft_strlcat(str, buf, ft_strlen(str) + read_count + 1);
	}
	return (str);
}
