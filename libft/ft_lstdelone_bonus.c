/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilefebv <lilefebv@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 16:42:49 by lilefebv          #+#    #+#             */
/*   Updated: 2024/11/24 13:14:50 by lilefebv         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include "stdio.h"

void    ft_lstdelone(t_list **first, t_list *lst)
{
	t_list *current;

	if (!first || !*first || !lst)
		return;
	if (*first == lst)
	{
		*first = lst->next;
		free(lst->content);
		free(lst);
	}
	else
	{
		current = *first;
		while(current)
		{
			if (current->next == lst)
			{
				current->next = lst->next;
				free(lst->content);
				free(lst);
				lst = NULL;
			}
			current = current->next;
		}
	}
}
