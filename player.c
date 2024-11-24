/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilefebv <lilefebv@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 08:55:22 by lilefebv          #+#    #+#             */
/*   Updated: 2024/11/24 15:09:29 by lilefebv         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "includes/global.h"

t_player	*init_player(int win_height)
{
	t_player *player;

	player = malloc(sizeof(t_player));
	if(!player)
		return (NULL);
	player->posX = 10;
	player->posY = win_height / 2;
	player->pv = 3;
	return (player);
}

void	move_player(t_player *player, int input, int lines, int cols, WINDOW *game)
{
	mvwprintw(game, player->posY, player->posX, " ");
	switch (input) {
		case KEY_UP:
			if (player->posY > 1) player->posY = player->posY - 1; // Déplacer vers le haut
			break;
		case KEY_DOWN:
			if (player->posY < lines - 2) player->posY = player->posY + 1; // Déplacer vers le bas
			break;
		case KEY_LEFT:
			if (player->posX > 1) player->posX = player->posX - 1; // Déplacer vers la gauche
			break;
		case KEY_RIGHT:
			if (player->posX < cols - 2) player->posX = player->posX + 1; // Déplacer vers la droite
			break;
	}
}

void	shoot_player(int input, t_list **frst_shoot, int playerX, int playerY)
{
	if (input == ' ')
	{
		t_shoot *shoot_el = malloc(sizeof(t_shoot));
		if (!shoot_el)
			return ;
		shoot_el->posY = playerY;
		shoot_el->posX = playerX + 1;
		ft_lstadd_back(frst_shoot, ft_lstnew(shoot_el));
	}
}
void	check_enemy_player(t_list **lst_enemys, int playerX, int playerY, int *running, int *death_screen)
{
	t_list	*enemys = *lst_enemys;
	t_enemy	*enemy = NULL;
	
	while(enemys)
	{
		if(enemys->content)
			enemy = enemys->content;
		else
			return;
		if(enemy->posX == playerX && enemy->posY == playerY)
		{
			*running = 0;
			*death_screen = 1;
		}
		enemys = enemys->next;
	}
	
}

void	check_enemy_shoot(t_list **lst_shoots, t_player *player, int *running, int *death_screen, WINDOW *game)
{
	t_list	*shoots = *lst_shoots;
	t_shoot	*shoot = NULL;
	
	while(shoots)
	{
		if(shoots->content)
			shoot = shoots->content;
		else
			return;
		if(shoot->posX == player->posX && shoot->posY == player->posY)
		{
			player->pv--;
			mvwprintw(game, shoot->posY, shoot->posX + 1, " ");
			ft_lstdelone(lst_shoots, shoots);
			if(player->pv == 0)
			{
				*running = 0;
				*death_screen = 1;
			}
			return ;
		}
		shoots = shoots->next;
	}
}