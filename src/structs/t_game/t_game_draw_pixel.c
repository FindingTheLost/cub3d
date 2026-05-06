/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_game_draw_pixel.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-alme <pde-alme@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 20:36:27 by pde-alme          #+#    #+#             */
/*   Updated: 2026/05/05 23:46:37 by pde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../t_game_struct.h"

/* This function shall grab the pixel location offset from the address of the
 * image struct and modify its value, in real-time, to the color passed as
 * parameter.
 *
 * Keep in mind that 'x' and 'y' are the pixel locations of the screen we want
 * to draw at. If a screen has 960 x 540 pixels, the width ('x') goes from 0 to
 * 959 and the height ('y') from 0 to 539.
 * 
 * In the formula "y * line_length + x * (bpp / 8)" (returns an int):
 * 	- "bpp" or "bits per pixel" gives information about how many color spectres
 * 	  there are per pixel. If 32, it means there are 32 bits per pixel or
 * 	  32 / 8 = 4 bytes per pixel. These bytes refer to the 'A'lpha, 'R'ed,
 * 	  'G'reen and 'B'lue color spectres, which are byte/unsigned char sized.
 * 	  Here, 0 represents black and 255 the max spectre color.
 *
 *	- Returns an int to the offset of the image buffer, which can be abstractly
 *	  seen as a 2D matrix of bytes in a segmented sequence of chars (a char *).
 *	  Example: "Row1startRow1endRow2startRow2endRow3startRow3end".
 *	  Since it only returns the offset, we must then add this offset to the
 *	  memory location of the image address.
 *
 *	- "line_length" refers to the length of one row of pixels (usually, the
 *	  width * x color spectres, (4) in this case). If "line_length" represents
 *	  a screen pixel row, it means the first byte starts at 0 (representing the
 *	  first of 4 color spectres of the first pixel) and ends in
 *	  "line_length" - 1 (representing the last color spectre of the last pixel
 *	  of the row). To access the first line all it must be done is
 *	  0 * "line_length". To access the second line, a simple 1 * "line_length"
 *	  will give access to the first pixel of the second row (starting from size
 *	  "line_length", which, in the above resolution, is 3840);
 *
 *	In the end, storing the sum of the address of the image buffer with the
 *	memory offset of the pixel in a char * results in having a pointer to the
 *	pixel itself, which, if we want to modify its value by 4 bytes and 4 bytes
 *	only, it has to be converted to an unsigned integer pointer (because the
 *	value of the memory stored in a pointer is the same, whatever the type of
 *	pointer, which just represents a memory location unsigned long integer,
 *	which is also why it can't and mustn't be converted to a normal int pointer)
 *	and apply the "color" passed as parameter into the pointer, which will
 *	just modify up to 4 bytes.
 */
void	t_game_draw_pixel(t_image *image, int x, int y, int color)
{
	char	*pixel;

	pixel = image->address + (y * image->line_length + x * (image->bpp / 8));
	*(unsigned int *)pixel = color;
}
