/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_key_build.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rogde-so <rogde-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 20:50:27 by pde-alme          #+#    #+#             */
/*   Updated: 2026/05/14 02:10:25 by rogde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../t_key_struct.h"

t_key	*t_key_build(void)
{
	t_key	*key;

	key = malloc(sizeof(t_key));
	if (!key)
		return (t_key_malloc_error(), NULL);
	key->w = false;
	key->s = false;
	key->a = false;
	key->d = false;
	key->m = false;
	key->left = false;
	key->right = false;
	key->space = false;
	key->mouse_x = -1;
	key->mouse_axis = 0;
	return (key);
}
