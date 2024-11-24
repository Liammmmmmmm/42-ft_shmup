/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilefebv <lilefebv@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 08:55:22 by lilefebv          #+#    #+#             */
/*   Updated: 2024/11/24 11:33:25 by lilefebv         ###   ########lyon.fr   */
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
		shoot_el->posX = playerX;
		ft_lstadd_back(frst_shoot, ft_lstnew(shoot_el));
	}
}
