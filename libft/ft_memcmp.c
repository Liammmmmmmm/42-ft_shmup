/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilefebv <lilefebv@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 14:54:59 by lilefebv          #+#    #+#             */
/*   Updated: 2024/11/08 12:28:03 by lilefebv         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	if (n == 0)
		return (0);
	i = 0;
	while (*(((const unsigned char *)s1) + i)
		== *(((const unsigned char *)s2) + i) && i + 1 < n)
		i++;
	return (*(((unsigned char *)s1) + i) - *(((unsigned char *)s2) + i));
}
