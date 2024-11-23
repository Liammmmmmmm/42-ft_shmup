/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstgetprev.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilefebv <lilefebv@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 13:59:37 by lilefebv          #+#    #+#             */
/*   Updated: 2024/11/23 14:27:16 by lilefebv         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstgetprev(t_list *first, t_list *actual)
{
	t_list	*temp;
	t_list	*res;

	if (first == NULL || actual == NULL || first->content == actual->content)
		return (NULL);
	temp = first;
	res = NULL;
	while (temp->next)
	{
		res = temp;
		temp = temp->next;
		if (temp->content == actual->content)
			return (res);
		else
			res = NULL;
	}
	return (NULL);
}
