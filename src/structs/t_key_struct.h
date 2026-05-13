/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_key_struct.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rogde-so <rogde-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 20:45:37 by pde-alme          #+#    #+#             */
/*   Updated: 2026/05/13 18:47:34 by pde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_KEY_STRUCT_H
# define T_KEY_STRUCT_H

# include "../../libft/libft.h"

/* Defines a set of keys that are pressed and held in a given frame.
 */
typedef struct s_key
{
	int	w;
	int	s;
	int	a;
	int	d;
	int	m;
	int	left;
	int	right;
	int	space;
}	t_key;

t_key	*t_key_build(void);
void	t_key_debug(t_key *key);
void	t_key_destroy(t_key *key);
void	t_key_malloc_error(void);
void	t_key_struct_error(void);
int		t_key_populate(t_key **key_ref);

#endif
