/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_invalid_resolution.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-alme <pde-alme@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 00:09:01 by pde-alme          #+#    #+#             */
/*   Updated: 2026/05/08 00:47:21 by pde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

static int	wrong_resolution(void)
{
	if (W_WIDTH == 640 && W_HEIGHT == 360)
		return (false);
	else if (W_WIDTH == 960 && W_HEIGHT == 540)
		return (false);
	else if (W_WIDTH == 1280 && W_HEIGHT == 720)
		return (false);
	else if (W_WIDTH == 1366 && W_HEIGHT == 768)
		return (false);
	else if (W_WIDTH == 1600 && W_HEIGHT == 900)
		return (false);
	else if (W_WIDTH == 1920 && W_HEIGHT == 1080)
		return (false);
	else if (W_WIDTH == 2560 && W_HEIGHT == 1440)
		return (false);
	else if (W_WIDTH == 3840 && W_HEIGHT == 2160)
		return (false);
	else if (W_WIDTH == 7680 && W_HEIGHT == 4320)
		return (false);
	return (true);
}

int	game_invalid_resolution(void)
{
	if (wrong_resolution())
	{
		ft_printf(RED_LIGH "Error\n" DEF);
		ft_printf("Aspect ratio or resolution not supported!\n");
		return (false);
	}
	return (true);
}
