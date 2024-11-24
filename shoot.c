/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shoot.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilefebv <lilefebv@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 09:04:11 by lilefebv          #+#    #+#             */
/*   Updated: 2024/11/24 19:06:15 by lilefebv         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "includes/global.h"

int		shoot_check(t_shoot *shoot, int cols)
{
	if (shoot->posX == cols - 3)
		return (1);
	return (0);
}


int		shoot_check_enemy(t_shoot *shoot)
{
	if (shoot->posX >= 1)
		return (1);
	return (0);
}

void	move_shoot_enemy(t_list *shoot, int cols, t_list **frst_shoot, WINDOW *game)
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
		bonus++;
	}
	else
		shoot_el->posX = shoot_el->posX - 1;
	
}

int	move_shoot(t_list *shoot, int cols, t_list **frst_shoot, WINDOW *game)
{
	if (!shoot)
		return 1;
	if (!shoot->content)
		return 1;
	t_shoot *shoot_el = shoot->content;
	if (shoot_check(shoot->content, cols))
	{
		mvwprintw(game, shoot_el->posY, shoot_el->posX, "  ");
		ft_lstdelone(frst_shoot, shoot);
		shoot = NULL;
		bonus = 1;
		return (1);
	}
	else
		shoot_el->posX = shoot_el->posX + 1;
	return (0);
}


void	check_enemys_shoots(t_list *shoot, t_list **lst_enemys, t_list **frst_shoot, WINDOW *game)
{
	if(!shoot || !lst_enemys || !shoot->content || !frst_shoot)
		return;
	t_list	*enemys = *lst_enemys;
	t_list	*next = NULL;
	t_enemy	*enemy = NULL;
	t_shoot *shoot_el = shoot->content;

	while(enemys)
	{
		next = enemys->next;
		if(enemys->content)
			enemy = enemys->content;
		if((shoot_el && enemy->posX == shoot_el->posX && enemy->posY == shoot_el->posY ))
		{
			enemy->pv--;
			if(enemy->pv == 0)
			{
				if(enemy->type == 2)
					mvwprintw(game, shoot_el->posY, shoot_el->posX - 1, "    ");
				else
					mvwprintw(game, shoot_el->posY, shoot_el->posX - 1, "  ");
				if(enemy->type == 1)
					score += 1 * bonus;
				else if(enemy->type == 2)
					score += 20 * bonus;
				else if(enemy->type == 3)
					score += 5 * bonus;
				else if(enemy->type == 3)
					score += 10 * bonus;
				ft_lstdelone(lst_enemys, enemys);
				enemys = NULL;

			}	
			ft_lstdelone(frst_shoot, shoot);
			shoot = NULL;
			return;
		}
		enemys = next;
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
			if(move_shoot(lst, cols, frst_shoot, game) == 0)
				check_enemys_shoots(lst, lst_enemys, frst_shoot, game);
			lst = next;
		}
	}
}


void	upt_shoots_enemy(t_list **frst_shoot, int cols, WINDOW *game)
{
	if (frst_shoot && *frst_shoot)
	{
		t_list *lst = *frst_shoot;
		t_list *next = NULL;
		while(lst)
		{
			next = lst->next;
			move_shoot_enemy(lst, cols, frst_shoot, game);
			lst = next;
		}
	}
}