/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stars.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilefebv <lilefebv@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 12:06:51 by lilefebv          #+#    #+#             */
/*   Updated: 2024/11/24 12:29:11 by lilefebv         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "includes/global.h"


int		star_check(t_enemy *star)
{
	if (star->posX <= 1)
		return (1);
	return (0);
}

t_enemy		*init_star(int win_height, int win_length)
{
	t_enemy *enemy;

	enemy = malloc(sizeof(t_enemy));
	if(!enemy)
		return (NULL);
	enemy->posY = rand() % (win_height - 2) + 1;
	enemy->posX = win_length - 2;
	enemy->pv = 0;
	return (enemy);
}

void	move_star(t_list *stars, t_list **stars_first, WINDOW *game)
{
	if (!stars)
		return;
	if (!stars->content)
		return;
	t_enemy *star_el = stars->content;
	if (star_check(stars->content))
	{
		mvwprintw(game, star_el->posY, star_el->posX, " ");
		ft_lstdelone(stars_first, stars);
		stars = NULL;
	}
	else
	{
		star_el->posX = star_el->posX - 1;
		
	}
	
}

void	upt_stars(t_list **stars, WINDOW *game)
{
	if (stars && *stars)
	{
		t_list *lst = *stars;
		t_list *next = NULL;
		while(lst)
		{
			next = lst->next;
				move_star(lst, stars, game);
			lst = next;
		}
	}
}