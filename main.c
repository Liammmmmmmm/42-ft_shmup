/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilefebv <lilefebv@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 10:35:53 by lilefebv          #+#    #+#             */
/*   Updated: 2024/11/24 09:19:39 by lilefebv         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "includes/global.h"

int main(void) {
	setlocale(LC_ALL, "en_US.UTF-8");
    initscr();
	cbreak();
	nodelay(stdscr, TRUE);
	noecho();
	keypad(stdscr, TRUE);
	
	
    WINDOW	*game;
	WINDOW 	*infos;
	
	t_player	*player;
	int			score = 0;
	player = init_player(LINES - 5);
	if (!player)
		return (show_error("Error while creating the player"), 1);
	t_list		*enemy_list = NULL;
	t_list		*first_shoots = NULL;

	int				running = 1;
	int				input;
	struct timespec	ts_start, ts_now;
    double			elapsed_time = 0.0;
	int				frame_counter_shoot = 0;
	int				frame_counter_enemy = 0;
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
				// mvwprintw(infos, 1, 5, "Key pressed: %c", input);
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

			frame_counter_enemy++;
			if (frame_counter_enemy >= 10)
			{
				upt_enemies(&enemy_list, game);
				frame_counter_enemy = 0;
			}
			
        }

		usleep(1000);
	}
	ft_lstclear(&enemy_list, free);
	ft_lstclear(&first_shoots, free);
	free(player);
    endwin();    
    return 0;
}
