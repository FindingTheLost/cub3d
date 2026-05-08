/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_key_build.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-alme <pde-alme@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 20:50:27 by pde-alme          #+#    #+#             */
/*   Updated: 2026/05/06 20:52:08 by pde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../t_key_struct.h"

t_key	*t_key_build(void)
{
	t_key	*key;

	key = malloc(sizeof(t_key));
	if (!key)
		return (t_key_malloc_error(), NULL);
	key->up = false;
	key->down = false;
	key->left = false;
	key->right = false;
	return (key);
}
