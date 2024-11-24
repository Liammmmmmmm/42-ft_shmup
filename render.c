/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilefebv <lilefebv@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 09:10:17 by lilefebv          #+#    #+#             */
/*   Updated: 2024/11/24 09:10:29 by lilefebv         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "includes/global.h"

void	show_error(char *error)
{
	ft_putstr_fd(error, 1);
}

void	print_player(WINDOW *game, t_player *player)
{
	mvwprintw(game, player->posY, player->posX, ">");
}

void	print_monsters(WINDOW *game, t_list *enemy_list)
{
	t_list *temp;
	t_enemy *enemy;

	if (enemy_list == NULL)
		return ;
	temp = enemy_list;
	enemy = temp->content;
	while (temp)
	{
		mvwprintw(game, enemy->posY, enemy->posX, "G");
		temp = temp->next;
	}
}

void	print_shoots(WINDOW *game, t_list *shoots)
{
	t_list *temp;
	t_shoot *shoot;

	if (shoots == NULL)
		return ;
	temp = shoots;
	shoot = temp->content;
	while (temp)
	{
		mvwprintw(game, shoot->posY, shoot->posX - 1, " ");
		mvwprintw(game, shoot->posY, shoot->posX, "->");
		temp = temp->next;
		if (temp)
			shoot = temp->content;
	}
}

void	render_game(WINDOW *game, t_player *player, t_list *enemy_list, t_list *shoots)
{
	if(player)
		print_player(game, player);
	if(enemy_list)
		print_monsters(game, enemy_list);
	if(shoots)
		print_shoots(game, shoots);
	wrefresh(game);
}

void	render_infos(WINDOW *infos, int score, t_player *player)
{	
	attron(A_BOLD);
    mvwprintw(infos, 2, 5, "Score %d", score);
	if (player->pv == 3)
		mvwprintw(infos, 2, COLS - 9, "♥♥♥");
	else if (player->pv == 2)
		mvwprintw(infos, 2, COLS - 9, "♥♥♡");
	else if (player->pv == 1)
		mvwprintw(infos, 2, COLS - 9, "♥♡♡");
	else if (player->pv == 0)
		mvwprintw(infos, 2, COLS - 9, "♡♡♡");
	attroff(A_BOLD);
	
	wrefresh(infos);
}