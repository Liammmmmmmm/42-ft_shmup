/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilefebv <lilefebv@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 16:42:49 by lilefebv          #+#    #+#             */
/*   Updated: 2024/11/23 14:25:38 by lilefebv         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list **first, t_list *lst, void (*del)(void*))
{
	t_list	*previous;

	if (lst == NULL)
		return ;
	previous = ft_lstgetprev(*first, lst);
	if (!previous)
		*first = lst->next;
	else
		previous->next = lst->next;
	del(lst->content);
	free(lst);
}
