/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitsato <mitsato@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 17:29:35 by mitsato           #+#    #+#             */
/*   Updated: 2025/10/20 18:23:42 by mitsato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*swap_ascii(char *str, int size_plus_one)
{
	while (size_plus_one > 0)
	{
		str[size_plus_one] = str[size_plus_one - 1];
		--size_plus_one;
	}
	return (str);
}

static char	*set_ascii(int nbr, int count, int *size)
{
	char	*ascii;

	if (nbr > -10)
	{
		ascii = malloc((count + 2) * sizeof(char));
		if (!ascii)
			return (NULL);
		*size = count;
		ascii[*size - count] = '0' - nbr;
		ascii[count + 1] = '\0';
		return (ascii);
	}
	else
	{
		ascii = set_ascii(nbr / 10, count + 1, size);
		if (!ascii)
			return (NULL);
		ascii[*size - count] = '0' - (nbr % 10);
		return (ascii);
	}
}

char	*ft_itoa(int n)
{
	int		len;
	char	*ascii;

	if (n >= 0)
	{
		n = -n;
		ascii = set_ascii(n, 0, &len);
	}
	else
	{
		ascii = set_ascii(n, 1, &len);
		if (!ascii)
			return (NULL);
		ascii = swap_ascii(ascii, len);
		ascii[0] = '-';
	}
	return (ascii);
}
