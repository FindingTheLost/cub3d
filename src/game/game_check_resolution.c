/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_check_resolution.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rogde-so <rogde-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 00:09:01 by pde-alme          #+#    #+#             */
/*   Updated: 2026/05/13 22:50:34 by rogde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

static int	wrong_resolution(void)
{
	if ((W_WIDTH == 640 && W_HEIGHT == 360)
		|| (W_WIDTH == 960 && W_HEIGHT == 540)
		|| (W_WIDTH == 1280 && W_HEIGHT == 720)
		|| (W_WIDTH == 1366 && W_HEIGHT == 768)
		|| (W_WIDTH == 1600 && W_HEIGHT == 900)
		|| (W_WIDTH == 1920 && W_HEIGHT == 1080)
		|| (W_WIDTH == 2560 && W_HEIGHT == 1440)
		|| (W_WIDTH == 3840 && W_HEIGHT == 2160)
		|| (W_WIDTH == 7680 && W_HEIGHT == 4320))
		return (false);
	return (true);
}

int	game_check_resolution(void)
{
	if (wrong_resolution())
	{
		ft_printf(RED_LIGH "Error\n" DEF);
		ft_printf("Aspect ratio or resolution not supported, please change");
		ft_printf(" W_WIDTH and W_HEIGHT macro values and recompile!\n");
		return (false);
	}
	return (true);
}
