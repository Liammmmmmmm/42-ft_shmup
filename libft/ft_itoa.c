/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilefebv <lilefebv@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 17:40:20 by lilefebv          #+#    #+#             */
/*   Updated: 2024/11/10 15:04:53 by lilefebv         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_get_n_size(int n)
{
	size_t	nsize;

	if (n == 0)
		return (1);
	nsize = 0;
	if (n < 0)
	{
		nsize++;
		n = -n;
	}
	while (n > 0)
	{
		nsize++;
		n = n / 10;
	}
	return (nsize);
}

char	*ft_itoa(int n)
{
	char	*res;
	size_t	size;
	size_t	i;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	size = ft_get_n_size(n);
	res = malloc(sizeof(char) * (size + 1));
	if (!res)
		return (NULL);
	i = 0;
	if (n < 0)
	{
		res[0] = '-';
		i++;
		n = -n;
	}
	res[size] = 0;
	while (i < size)
	{
		res[size - 1] = n % 10 + '0';
		n = n / 10;
		size--;
	}
	return (res);
}
