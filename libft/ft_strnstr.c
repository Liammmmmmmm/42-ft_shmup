/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilefebv <lilefebv@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 15:31:38 by lilefebv          #+#    #+#             */
/*   Updated: 2024/11/08 12:22:24 by lilefebv         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	pos;
	size_t	little_len;
	size_t	big_len;

	pos = 0;
	little_len = ft_strlen(little);
	if (little_len == 0)
		return ((char *)big);
	big_len = ft_strlen(big);
	while (pos < len && pos < big_len)
	{
		if (pos + little_len > big_len || pos + little_len > len)
			return (((void *)0));
		if (ft_strncmp(big, little, little_len) == 0)
			return ((char *)big);
		pos++;
		big++;
	}
	return (((void *)0));
}
