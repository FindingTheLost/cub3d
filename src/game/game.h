/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-alme <pde-alme@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 18:22:04 by pde-alme          #+#    #+#             */
/*   Updated: 2026/05/02 01:56:13 by pde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# include "../../libft/libft.h"
# include "../structs/t_cub_struct.h"
# include "../structs/t_game_struct.h"
# include "../structs/t_player_struct.h"
# include "../structs/t_map_struct.h"

int	game(t_cub *file);
int	game_init_vars(t_cub **file, t_game **game, t_player **player, t_map **map);

#endif
