/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_lib.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilefebv <lilefebv@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 10:35:53 by lilefebv          #+#    #+#             */
/*   Updated: 2024/11/23 18:35:53 by lilefebv         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "includes/global.h"

void	show_error(char *error)
{
	
}

t_player	*init_player(int win_height, int win_length)
{
	t_player *player;

	player = malloc(sizeof(t_player));
	if(!player)
		return (NULL);
	player->posX = 10;
	player->posY = win_height / 2;
	player->pv = 5;
	return (player);
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
int		shoot_check(t_shoot *shoot, int cols)
{
		if (shoot->posX == cols - 2)
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
		ft_lstdelone(frst_shoot, shoot);
		shoot = NULL;
		printf("test %p", shoot);
	}
	else
		shoot_el->posX = shoot_el->posX + 1;
	
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

void	upt_shoots(t_list **frst_shoot, int cols, WINDOW *game)
{
		if (frst_shoot)
		{
			if(*frst_shoot)
			{
			t_list *lst = *frst_shoot;
			t_list *next = NULL;
			while(lst)
			{
				next = lst->next;
				move_shoot(lst, cols, frst_shoot, game);
				lst = next;
				
			}
			}
		}
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
		mvwprintw(game, shoot->posY, shoot->posX, "(==)");
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
    mvwprintw(infos, 2, 3, "Score");
	mvwprintw(infos, 2, COLS - 7, "PV");
	attroff(A_BOLD);
	mvwprintw(infos, 2, 9, "%d", player->posX);
	
	wrefresh(infos);
}

int main(void) {
    initscr();
	cbreak();
	nodelay(stdscr, TRUE);
	noecho();
	keypad(stdscr, TRUE);
	
    WINDOW	*game;
	WINDOW 	*infos;
	
	t_player	*player;
	int			score = 0;
	player = init_player(LINES - 5, COLS);
	if (!player)
		return (show_error("Error while creating the player"), 1);
	t_list		*enemy_list = NULL;
	t_list		*first_shoots = NULL;

	int				running = 1;
	int				input;
	struct timespec	ts_start, ts_now;
    double			elapsed_time = 0.0;
	int				frame_counter_shoot = 0;
	double			enemy_spawn_timer = 0.0;
    const double	frame_time = 1.0 / 60.0;

	clock_gettime(CLOCK_MONOTONIC, &ts_start);
    
    game = subwin(stdscr, LINES - 5, COLS, 0, 0);
	infos = subwin(stdscr, 5, COLS, LINES - 5, 0);
   
    box(game, ACS_VLINE, ACS_HLINE);
	box(infos, ACS_VLINE, ACS_HLINE);
	while (running)
	{
		input = getch();
        if (input != ERR) {
            if (input == 'q') {
                running = 0;
            } else {
				mvwprintw(infos, 1, 5, "Key pressed: %c", input);
				shoot_player(input, &first_shoots, player->posX, player->posY);
                move_player(player, input, LINES - 5, COLS, game);
            }
        }

		clock_gettime(CLOCK_MONOTONIC, &ts_now);
        elapsed_time += (ts_now.tv_sec - ts_start.tv_sec) +
                        (ts_now.tv_nsec - ts_start.tv_nsec) / 1e9;

		enemy_spawn_timer += elapsed_time;
		if (enemy_spawn_timer >= 1.0)
		{
			t_enemy *enemy = init_enemy(LINES - 5, COLS);
			if (!enemy)
				return (show_error("Error while creating the enemy"), 1);
			ft_lstadd_back(&enemy_list, ft_lstnew(enemy));
			enemy_spawn_timer = 0.0;
		}

		if (elapsed_time >= frame_time) {
			render_game(game, player, enemy_list, first_shoots);
			render_infos(infos, score, player);
            ts_start = ts_now;
            elapsed_time = 0.0;

			frame_counter_shoot++;
			if (frame_counter_shoot >= 2)
			{
				upt_shoots(&first_shoots, COLS, game);
				frame_counter_shoot = 0;
			}
        }

		usleep(1000);
	}
    endwin();    
    return 0;
}
