/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keitotak <keitotak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 22:01:19 by keitotak          #+#    #+#             */
/*   Updated: 2026/06/26 22:01:27 by keitotak         ###   ########.fr       */
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
