/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilefebv <lilefebv@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 10:31:06 by lilefebv          #+#    #+#             */
/*   Updated: 2024/11/24 15:06:04 by lilefebv         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GLOBAL_H
# define FT_GLOBAL_H

# define ENEMY_BASE_SPEED 10

# include "../libft/libft.h"
# include "struct.h"
# include <ncurses.h>
# include <time.h>
# include <unistd.h>
# include <locale.h>

# define PLAYER ">"
# define ENEMY "E"
# define STAR "☼"


extern int score;

/*****************************************************************************/
/*                              PLAYER FUNCTION                              */
/*****************************************************************************/

t_player	*init_player(int win_height);
void	move_player(t_player *player, int input, int lines, int cols, WINDOW *game);
void	shoot_player(int input, t_list **frst_shoot, int playerX, int playerY);
void	check_enemy_player(t_list **lst_enemys, int playerX, int playerY, int *running, int *death_screen);
void	check_enemy_shoot(t_list **lst_shoots, t_player *player, int *running, int *death_screen, WINDOW *game);


/*****************************************************************************/
/*                              ENEMY FUNCTION                               */
/*****************************************************************************/

t_enemy		*init_enemy(int win_height, int win_length);
void		upt_enemies(t_list **enemies, WINDOW *game, int lines , t_list **frst_shoot);
void		shoot_enemy(t_list **frst_shoot, int enemyX, int enemyY);


/*****************************************************************************/
/*                              SHOOTS FUNCTION                              */
/*****************************************************************************/

int		shoot_check(t_shoot *shoot, int cols);
void	upt_shoots(t_list **frst_shoot, int cols, WINDOW *game, t_list **enemies);
void	move_shoot_enemy(t_list *shoot, int cols, t_list **frst_shoot, WINDOW *game);
void	upt_shoots_enemy(t_list **frst_shoot, int cols, WINDOW *game);



/*****************************************************************************/
/*                              RENDER FUNCTION                              */
/*****************************************************************************/

void	show_error(char *error);
void	render_game(WINDOW *game, t_player *player, t_list *enemy_list, t_list *shoots, t_list *shoots_enemies, t_list *stars, int cols);
void	render_infos(WINDOW *infos, int score, t_player *player, double timer);



/*****************************************************************************/
/*                              STARS FUNCTION                               */
/*****************************************************************************/

t_enemy		*init_star(int win_height, int win_length);
void		upt_stars(t_list **stars, WINDOW *game);


#endif