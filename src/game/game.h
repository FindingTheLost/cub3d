/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rogde-so <rogde-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 18:22:04 by pde-alme          #+#    #+#             */
/*   Updated: 2026/05/13 23:20:21 by rogde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# include "../../libft/libft.h"
# include "../structs/t_cub_struct.h"
# include "../structs/t_game_struct.h"

int		game(t_cub *file);
int		game_update(t_game *game);
int		game_check_resolution(void);
int		game_init_vars(t_cub *file, t_game **game);
void	game_init_hooks(t_game *game);

#endif
