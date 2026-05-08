/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_key_populate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-alme <pde-alme@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 20:57:06 by pde-alme          #+#    #+#             */
/*   Updated: 2026/05/06 20:58:47 by pde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../t_key_struct.h"

int	t_key_populate(t_key **key_ref)
{
	*key_ref = t_key_build();
	if (!*key_ref)
		return (false);
	return (true);
}
