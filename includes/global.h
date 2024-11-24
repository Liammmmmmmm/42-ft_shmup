/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilefebv <lilefebv@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 10:31:06 by lilefebv          #+#    #+#             */
/*   Updated: 2024/11/24 09:19:34 by lilefebv         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GLOBAL_H
# define FT_GLOBAL_H

# include "../libft/libft.h"
# include "struct.h"
# include <ncurses.h>
# include <time.h>
# include <unistd.h>
# include <locale.h>

/*****************************************************************************/
/*                              PLAYER FUNCTION                              */
/*****************************************************************************/

t_player	*init_player(int win_height);
void	move_player(t_player *player, int input, int lines, int cols, WINDOW *game);
void	shoot_player(int input, t_list **frst_shoot, int playerX, int playerY);



/*****************************************************************************/
/*                              ENEMY FUNCTION                               */
/*****************************************************************************/

t_enemy		*init_enemy(int win_height, int win_length);
void		upt_enemies(t_list **enemies, WINDOW *game);


/*****************************************************************************/
/*                              SHOOTS FUNCTION                              */
/*****************************************************************************/

int		shoot_check(t_shoot *shoot, int cols);
void	move_shoot(t_list *shoot, int cols, t_list **frst_shoot, WINDOW *game);
void	upt_shoots(t_list **frst_shoot, int cols, WINDOW *game);



/*****************************************************************************/
/*                              RENDER FUNCTION                              */
/*****************************************************************************/

void	show_error(char *error);
void	render_game(WINDOW *game, t_player *player, t_list *enemy_list, t_list *shoots);
void	render_infos(WINDOW *infos, int score, t_player *player);




#endif