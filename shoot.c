/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shoot.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilefebv <lilefebv@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 09:04:11 by lilefebv          #+#    #+#             */
/*   Updated: 2024/11/24 11:18:15 by lilefebv         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "includes/global.h"

int		shoot_check(t_shoot *shoot, int cols)
{
	if (shoot->posX == cols - 3)
		return (1);
	return (0);
}

void	move_shoot(t_list *shoot, int cols, t_list **frst_shoot, WINDOW *game)
{
	if (!shoot)
		return;
	if (!shoot->content)
		return;
	t_shoot *shoot_el = shoot->content;
	if (shoot_check(shoot->content, cols))
	{
		mvwprintw(game, shoot_el->posY, shoot_el->posX, "  ");
		ft_lstdelone(frst_shoot, shoot);
		shoot = NULL;
	}
	else
		shoot_el->posX = shoot_el->posX + 1;
	
}
void	check_enemys_shoots(t_list *shoot, t_list **lst_enemys, t_list **frst_shoot)
{
	t_list	*enemys = *lst_enemys;
	t_enemy	*enemy = NULL;
	if(!shoot)
		return;
	t_shoot *shoot_el = shoot->content;

	while(enemys)
	{
		if(enemys->content)
			enemy = enemys->content;
		if(enemy->posX == shoot_el->posX && enemy->posY == shoot_el->posY)
			{
				ft_lstdelone(lst_enemys, enemys);
				ft_lstdelone(frst_shoot, shoot);
				score++;
			}
		enemys = enemys->next;
	}
}

void	upt_shoots(t_list **frst_shoot, int cols, WINDOW *game, t_list **lst_enemys)
{
	if (frst_shoot && *frst_shoot)
	{
		t_list *lst = *frst_shoot;
		t_list *next = NULL;
		while(lst)
		{
			next = lst->next;
			move_shoot(lst, cols, frst_shoot, game);
			lst = next;
			check_enemys_shoots(lst, lst_enemys, frst_shoot);
		}
	}
}