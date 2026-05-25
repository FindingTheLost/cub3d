/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init_screen.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-alme <pde-alme@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 00:09:01 by pde-alme          #+#    #+#             */
/*   Updated: 2026/05/24 22:41:46 by pde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

/* Function that returns "true" if the number of rays value, chosen in the
 * "RAY_AMOUNT" macro, is not a divisor of the current resolution's "W_WIDTH".
 * Also returns "true" if "RAY_AMOUNT" is inferior to 2.
 */
static int	wrong_ray_amount(void)
{
	if ((int)RAY_AMOUNT != (float)RAY_AMOUNT)
		return (true);
	if (RAY_AMOUNT <= 1)
		return (true);
	if (RAY_AMOUNT > W_WIDTH)
		return (true);
	if ((int)W_WIDTH / RAY_AMOUNT != (float)W_WIDTH / RAY_AMOUNT)
		return (true);
	return (false);
}

/* Function that returns "true" if the current screen resolution "W_WIDTH" and
 * "W_HEIGHT" macros do not correspond to any of the sequences below.
 */
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

int	game_init_screen(void)
{
	if (wrong_resolution())
	{
		ft_printf(RED_LIGH "Error\n" DEF);
		ft_printf("Aspect ratio or resolution not supported, please change");
		ft_printf(" W_WIDTH and W_HEIGHT macro values and recompile!\n");
		return (false);
	}
	if (wrong_ray_amount())
	{
		ft_printf(RED_LIGH "Error\n" DEF);
		ft_printf("Bad number of rays were set, please change RAY_AMOUNT");
		ft_printf(" macro value and recompile!\n");
		return (false);
	}
	return (true);
}
