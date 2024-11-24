/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilefebv <lilefebv@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 09:01:54 by lilefebv          #+#    #+#             */
/*   Updated: 2024/11/24 15:34:32 by lilefebv         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "includes/global.h"

int		enemy_check(t_enemy *enemy)
{
	if (enemy->posX <= 1)
		return (1);
	return (0);
}

t_enemy		*init_enemy(int win_height, int win_length)
{
	t_enemy *enemy;

	enemy = malloc(sizeof(t_enemy));
	if(!enemy)
		return (NULL);
	enemy->posY = rand() % (win_height - 2) + 1;
	enemy->posX = win_length - 2;
	enemy->pv = 1;
	return (enemy);
}

void	move_enemy(t_list *enemies, t_list **enemies_first, WINDOW *game, int lines)
{
	if (!enemies)
		return;
	if (!enemies->content)
		return;
	t_enemy *enemy_el = enemies->content;
	if (enemy_check(enemies->content))
	{
		mvwprintw(game, enemy_el->posY, enemy_el->posX, " ");
		ft_lstdelone(enemies_first, enemies);
		enemies = NULL;
	}
	else
	{
		enemy_el->posX = enemy_el->posX - 1;
		if (rand() % 10 == 0)
		{
			if (rand() % 2 == 0)
			{
				if (enemy_el->posY > 2)
				{
					enemy_el->posY = enemy_el->posY - 1;
				}
			}
			else
			{
				if (enemy_el->posY < lines - 2)
				{
					enemy_el->posY = enemy_el->posY + 1;
				}
			}
		}
	}
	
}

void	upt_enemies(t_list **enemies, WINDOW *game, int lines , t_list **frst_shoot, int timer)
{
	if (enemies && *enemies)
	{
		t_list *lst = *enemies;
		t_list *next = NULL;
		t_enemy *enemy = NULL;
		while(lst)
		{
			next = lst->next;
			if(lst->content)
				enemy = lst->content;
			if (rand() % 3 == 0) // une chance sur 3 de bouger un mob
			{
				move_enemy(lst, enemies, game, lines);
			}
			else if (rand() % (50 + timer / 10) == 0)
			{
				shoot_enemy(frst_shoot, enemy->posX, enemy->posY);
			}
			lst = next;
		}
	}
}


void	shoot_enemy(t_list **frst_shoot, int enemyX, int enemyY)
{
		t_shoot *shoot_el = malloc(sizeof(t_shoot));
		if (!shoot_el)
			return ;
		shoot_el->posY = enemyY;
		shoot_el->posX = enemyX - 1;
		ft_lstadd_back(frst_shoot, ft_lstnew(shoot_el));
}