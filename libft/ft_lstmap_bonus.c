/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilefebv <lilefebv@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 17:26:06 by lilefebv          #+#    #+#             */
/*   Updated: 2024/11/15 14:10:35 by lilefebv         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*ft_clear_all(t_list *newlist, void (*del)(void *), void *newc)
{
	if (newc)
		del(newc);
	if (newlist)
		ft_lstclear(&newlist, del);
	return (NULL);
}

static t_list	*new_node(t_list *l, void *(*f)(void *), void (*del)(void *))
{
	void	*new_content;
	t_list	*new_node;

	new_content = f(l->content);
	if (!new_content)
		return (NULL);
	new_node = ft_lstnew(new_content);
	if (!new_node)
	{
		del(new_content);
		return (NULL);
	}
	return (new_node);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*temp;

	if (!lst || !f || !del)
		return (NULL);
	new_list = new_node(lst, f, del);
	if (!new_list)
		return (NULL);
	temp = new_list;
	lst = lst->next;
	while (lst)
	{
		temp->next = new_node(lst, f, del);
		if (!temp->next)
			return (ft_clear_all(new_list, del, NULL));
		temp = temp->next;
		lst = lst->next;
	}
	return (new_list);
}
