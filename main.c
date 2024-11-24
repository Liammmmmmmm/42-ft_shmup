/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilefebv <lilefebv@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 10:35:53 by lilefebv          #+#    #+#             */
/*   Updated: 2024/11/24 18:17:58 by lilefebv         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "includes/global.h"

int	score = 0;

int	ft_get_n_size(int n)
{
	int	nsize;

	if (n == 0)
		return (1);
	nsize = 0;
	while (n > 0)
	{
		nsize++;
		n = n / 10;
	}
	return (nsize);
}

int main(void) {
	setlocale(LC_ALL, "en_US.UTF-8");
    initscr();
	nodelay(stdscr, TRUE);
	noecho();
	keypad(stdscr, TRUE);
	curs_set(0);
	cbreak();

	if (COLS < 80 || LINES < 24) {
        endwin();
        printf("Le terminal est trop petit. Résolution minimale requise : 80x24.\n");
        return 1;          
    }

	int		base_munitions = 15;
	double	muntion_reload_delay = 1.0;
	double	muntion_reload_timer = 0.0;
	
    WINDOW	*game;
	WINDOW 	*infos;
	WINDOW 	*death_screen;
	WINDOW 	*menu;
	
	t_player	*player;
	t_list		*enemy_list = NULL;
	t_list		*first_shoots = NULL;
	t_list		*first_enemy_shoot = NULL;
	t_list		*stars = NULL;

	int	star_amount = LINES * COLS / 300;
	while (star_amount > 0)
	{
		t_enemy *star = init_star(LINES - 5, (rand() % (COLS - 4)) + 2);
		if (star)
		{
			ft_lstadd_back(&stars, ft_lstnew(star));
		}
		star_amount--;
	}

	int				running = 1;
	int				input;
	struct timespec	ts_start, ts_now;
    double			elapsed_time = 0.0;
	double			delta_time = 0.0;
	int				frame_counter_shoot = 0;
	int				frame_counter_enemy = 0;
	int				frame_counter_stars = 0;
	double			enemy_spawn_timer = 0.0;
    const double	frame_time = 1.0 / 60.0;
	double			timer = 0;
	
	double			enemy_speed = ENEMY_BASE_SPEED;
	
	int				youaredead_screen = 0;
	
	int				skippall = 0;

	clock_gettime(CLOCK_MONOTONIC, &ts_start);

	start_color();
	assume_default_colors(COLOR_WHITE, COLOR_BLACK);
	
	menu = subwin(stdscr, LINES, COLS, 0, 0);
	int		clignote = 0;
	char	*listPerso = " #>O@K&$ ";
	int		selected_char = 4;
	while (running)
	{
		clignote++;
		box(menu, ACS_VLINE, ACS_HLINE);
		mvwprintw(menu, 2, COLS / 2 - 81 / 2, "             _            _   _                                                  ");
		mvwprintw(menu, 3, COLS / 2 - 81 / 2, "  __ _  __ _| | __ _  ___| |_(_) ___   _ __   _____      __  _ __   _____      __");
		mvwprintw(menu, 4, COLS / 2 - 81 / 2, " / _` |/ _` | |/ _` |/ __| __| |/ __| | '_ \\ / _ \\ \\ /\\ / / | '_ \\ / _ \\ \\ /\\ / /");
		mvwprintw(menu, 5, COLS / 2 - 81 / 2, "| (_| | (_| | | (_| | (__| |_| | (__  | |_) |  __/\\ V  V /  | |_) |  __/\\ V  V / ");
		mvwprintw(menu, 6, COLS / 2 - 81 / 2, " \\__, |\\__,_|_|\\__,_|\\___|\\__|_|\\___| | .__/ \\___| \\_/\\_/   | .__/ \\___| \\_/\\_/  ");
		mvwprintw(menu, 7, COLS / 2 - 81 / 2, " |___/                                |_|                   |_|                  ");
		
		if (clignote == 6)
			mvwprintw(menu, 12, COLS / 2 - 22 / 2, "PRESS [SPACE] TO START");
		else if (clignote >= 12)
		{
			mvwprintw(menu, 12, COLS / 2 - 22 / 2, "                      ");
			clignote = 0;
		}

		mvwprintw(menu, 15, COLS / 2 - 23 / 2, "Select your spaceship!");
		mvwprintw(menu, 17, COLS / 2 - 25 / 2, "   ╒═════╦═════╦═════╕   ");
		mvwprintw(menu, 18, COLS / 2 - 25 / 2, "   │     ║     ║     │   ");
		mvwprintw(menu, 19, COLS / 2 - 25 / 2, "<  │     ║     ║     │  >");
		mvwprintw(menu, 20, COLS / 2 - 25 / 2, "   │     ║     ║     │   ");
		mvwprintw(menu, 21, COLS / 2 - 25 / 2, "   ╘═════╩═════╩═════╛   ");
		
		mvwprintw(menu, 19, COLS / 2 - 25 / 2 + 6, "%c", listPerso[selected_char - 1]);
		mvwprintw(menu, 19, COLS / 2 - 25 / 2 + 12, "%c", listPerso[selected_char]);
		mvwprintw(menu, 19, COLS / 2 - 25 / 2 + 18, "%c", listPerso[selected_char + 1]);

		input = getch();
		if (input != ERR) {
			if (input == 'q') {
				skippall = 1;
				running = 0;
			}
			else if (input == ' ') {
				running = 0;
			}
			else if (input == KEY_LEFT) {
				if (selected_char > 1)
					selected_char--;
			}
			else if (input == KEY_RIGHT) {
				if (selected_char < 7)
					selected_char++;
			}
		}
		
		wrefresh(menu);
		usleep(100000);
	}
	
	running = 1;
	clear();

	if (skippall == 0)
	{
		game = subwin(stdscr, LINES - 5, COLS, 0, 0);
		infos = subwin(stdscr, 5, COLS, LINES - 5, 0);

		init_pair(1 , COLOR_RED, COLOR_BLACK);
	
		box(game, ACS_VLINE, ACS_HLINE);
		box(infos, ACS_VLINE, ACS_HLINE);

		player = init_player(LINES - 5, base_munitions);
		if (!player)
			return (show_error("Error while creating the player"), 1);


		while (running)
		{
			input = getch();
			if (input != ERR) {
				if (input == 'q') {
					running = 0;
				} else {
					shoot_player(input, &first_shoots, player);
					move_player(player, input, LINES - 5, COLS, game);
				}
			}

			clock_gettime(CLOCK_MONOTONIC, &ts_now);
			delta_time = (ts_now.tv_sec - ts_start.tv_sec) +
						(ts_now.tv_nsec - ts_start.tv_nsec) / 1e9;
			ts_start = ts_now;

			elapsed_time += delta_time;
			timer += delta_time;
			enemy_spawn_timer += delta_time;

			if(timer - muntion_reload_timer > muntion_reload_delay)
			{
				if (player->munitions < base_munitions)
					player->munitions++;
				muntion_reload_timer = timer;
			}

			if (timer > 1.0)
				enemy_speed = ENEMY_BASE_SPEED / (1 + (timer / 20));
			
			if (enemy_spawn_timer >= enemy_speed / 3)
			{
				t_enemy *enemy = init_enemy(LINES - 5, COLS, (int)timer);
				if (enemy)
					ft_lstadd_back(&enemy_list, ft_lstnew(enemy));

				/*  SPAWN STARS  */
				t_enemy *star = init_star(LINES - 5, COLS);
				if (star)
				{
					ft_lstadd_back(&stars, ft_lstnew(star));
				}
				

				enemy_spawn_timer = 0.0;
			}

			if (elapsed_time >= frame_time) {
				render_game(game, player, enemy_list, first_shoots, first_enemy_shoot, stars, COLS, listPerso[selected_char]);
				render_infos(infos, score, player, timer, base_munitions);
				ts_start = ts_now;
				elapsed_time = 0.0;

				frame_counter_stars++;
				if (frame_counter_stars >= enemy_speed * 4.5)
				{
					upt_stars(&stars, game);
					frame_counter_stars = 0;
				}

				upt_shoots(&first_shoots, COLS, game, &enemy_list);

				frame_counter_shoot++;
				if (frame_counter_shoot >= 2)
				{
					upt_shoots_enemy(&first_enemy_shoot, COLS, game);
					frame_counter_shoot = 0;
				}
				
				frame_counter_enemy++;
				if (frame_counter_enemy >= enemy_speed)
				{
					upt_enemies(&enemy_list, game, LINES - 5, &first_enemy_shoot, timer);
					frame_counter_enemy = 0;
				}
				check_enemy_player(&enemy_list, player->posX, player->posY, &running, &youaredead_screen);
				check_enemy_shoot(&first_enemy_shoot, player, &running, &youaredead_screen, game);
			}

			usleep(1000);
		}

		ft_lstclear(&enemy_list, free);
		ft_lstclear(&first_shoots, free);
		ft_lstclear(&first_enemy_shoot, free);
		ft_lstclear(&stars, free);
		free(player);
		clear();
		
		start_color();
		assume_default_colors(COLOR_RED, COLOR_BLACK);
		// init_pair(1, COLOR_BLACK, COLOR_RED);

		if (youaredead_screen == 1)
		{		
			death_screen = subwin(stdscr, LINES, COLS, 0, 0);
			box(death_screen, ACS_VLINE, ACS_HLINE);
			
			attron(COLOR_PAIR(1));
			mvwprintw(death_screen, LINES / 2 - 3, COLS / 2 - 63 / 2, " _  _  __   _  _     __   ____  ____    ____  ____   __   ____ ");
			mvwprintw(death_screen, LINES / 2 - 2, COLS / 2 - 63 / 2, "( \\/ )/  \\ / )( \\   / _\\ (  _ \\(  __)  (    \\(  __) / _\\ (    \\");
			mvwprintw(death_screen, LINES / 2 - 1, COLS / 2 - 63 / 2, " )  /(  O )) \\/ (  /    \\ )   / ) _)    ) D ( ) _) /    \\ ) D (");
			mvwprintw(death_screen, LINES / 2, COLS / 2 - 63 / 2, "(__/  \\__/ \\____/  \\_/\\_/(__\\_)(____)  (____/(____)\\_/\\_/(____/");
			
			mvwprintw(death_screen, LINES / 2 + 2, COLS / 2 - ((8 + ft_get_n_size(score)) / 2), "Score : %d", score);
			attroff(COLOR_PAIR(1));
			
			wrefresh(death_screen);
			usleep(5000000);

		}
	}
	
    endwin();    
    return 0;
}
