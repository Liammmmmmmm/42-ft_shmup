/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilefebv <lilefebv@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 10:28:32 by lilefebv          #+#    #+#             */
/*   Updated: 2024/11/24 12:45:28 by lilefebv         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRUCT_H
# define FT_STRUCT_H

typedef struct s_player
{
	int	posX;
	int	posY;
	int	pv;
}					t_player;

typedef struct s_enemy
{
	int	posX;
	int	posY;
	int	pv;
}					t_enemy;

typedef struct s_shoot
{
	int posX;
	int posY;
	int dmg;
}					t_shoot;

#endif