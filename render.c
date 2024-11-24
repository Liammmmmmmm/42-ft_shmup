/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilefebv <lilefebv@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 09:10:17 by lilefebv          #+#    #+#             */
/*   Updated: 2024/11/24 15:05:09 by lilefebv         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "includes/global.h"

void	show_error(char *error)
{
	ft_putstr_fd(error, 1);
}

void	print_player(WINDOW *game, t_player *player)
{
	mvwprintw(game, player->posY, player->posX, PLAYER);
}

void	print_monsters(WINDOW *game, t_list *enemy_list, int cols)
{
	t_list *temp;
	t_enemy *enemy;

	if (enemy_list == NULL)
		return ;
	temp = enemy_list;
	enemy = temp->content;
	while (temp)
	{
		if (enemy->posX + 1 < cols - 1)
		{
			mvwprintw(game, enemy->posY, enemy->posX + 1, " ");
			mvwprintw(game, enemy->posY - 1, enemy->posX + 1, " ");
			mvwprintw(game, enemy->posY + 1, enemy->posX + 1, " ");
		}
		wattron(game, COLOR_PAIR(1));
		mvwprintw(game, enemy->posY, enemy->posX, ENEMY);
		wattroff(game, COLOR_PAIR(1));
		temp = temp->next;
		if (temp)
			enemy = temp->content;
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
		mvwprintw(game, shoot->posY, shoot->posX, "=>");
		temp = temp->next;
		if (temp)
			shoot = temp->content;
	}
}

void	print_stars(WINDOW *game, t_list *stars)
{
	t_list *temp;
	t_shoot *star;

	if (stars == NULL)
		return ;
	temp = stars;
	star = temp->content;
	while (temp)
	{
		mvwprintw(game, star->posY, star->posX + 1, " ");
		mvwprintw(game, star->posY, star->posX, STAR);
		temp = temp->next;
		if (temp)
			star = temp->content;
	}
}

void	print_shoots_enemies(WINDOW *game, t_list *shoots)
{
	t_list *temp;
	t_shoot *shoot;

	if (shoots == NULL)
		return ;
	temp = shoots;
	shoot = temp->content;
	while (temp)
	{
		mvwprintw(game, shoot->posY, shoot->posX + 1, " ");
		wattron(game, COLOR_PAIR(1));
		mvwprintw(game, shoot->posY, shoot->posX, "-");
		wattroff(game, COLOR_PAIR(1));
		temp = temp->next;
		if (temp)
			shoot = temp->content;
	}
}

void	render_game(WINDOW *game, t_player *player, t_list *enemy_list, t_list *shoots, t_list *shoots_enemies, t_list *stars, int cols)
{
	if(stars)
		print_stars(game, stars);
	if(player)
		print_player(game, player);
	if(enemy_list)
		print_monsters(game, enemy_list, cols);
	if(shoots_enemies)
		print_shoots_enemies(game, shoots_enemies);
	if(shoots)
		print_shoots(game, shoots);
	box(game, ACS_VLINE, ACS_HLINE);
	wrefresh(game);
}

void	render_infos(WINDOW *infos, int score, t_player *player, double timer)
{	
	attron(A_BOLD);
    mvwprintw(infos, 2, 5, "Score %d", score);
	mvwprintw(infos, 2, 35, "Timer %d", (int)timer);
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