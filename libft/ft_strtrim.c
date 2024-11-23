/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilefebv <lilefebv@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 10:10:17 by lilefebv          #+#    #+#             */
/*   Updated: 2024/11/15 14:08:41 by lilefebv         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_is_char_in_set(char c, const char *set)
{
	size_t	i;

	if (!set)
		return (0);
	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	new_size;
	size_t	start;
	char	*new_str;

	i = 0;
	start = 0;
	new_size = 0;
	while (s1[i] && ft_is_char_in_set(s1[i], set))
	{
		start++;
		i++;
	}
	while (s1[i])
	{
		if (ft_is_char_in_set(s1[i], set) == 0)
			new_size = i - start + 1;
		i++;
	}
	new_str = malloc(sizeof(char) * (new_size + 1));
	if (!new_str)
		return (NULL);
	ft_strlcpy(new_str, s1 + start, new_size + 1);
	return (new_str);
}
