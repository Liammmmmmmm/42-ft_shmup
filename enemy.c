/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilefebv <lilefebv@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 09:01:54 by lilefebv          #+#    #+#             */
/*   Updated: 2024/11/24 09:39:17 by lilefebv         ###   ########lyon.fr   */
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

void	move_enemy(t_list *enemies, t_list **enemies_first, WINDOW *game)
{
	if (!enemies)
		return;
	if (!enemies->content)
		return;
	t_enemy *enemy_el = enemies->content;
	if (enemy_check(enemies->content))
	{
		mvwprintw(game, enemy_el->posY, enemy_el->posX, "  ");
		ft_lstdelone(enemies_first, enemies);
		enemies = NULL;
	}
	else
		enemy_el->posX = enemy_el->posX - 1;
	
}

void	upt_enemies(t_list **enemies, WINDOW *game)
{
	if (enemies && *enemies)
	{
		t_list *lst = *enemies;
		t_list *next = NULL;
		while(lst)
		{
			next = lst->next;
			move_enemy(lst, enemies, game);
			lst = next;
			
		}
	}
}