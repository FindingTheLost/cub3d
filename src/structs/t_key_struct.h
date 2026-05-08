/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_key_struct.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rogde-so <rogde-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 20:45:37 by pde-alme          #+#    #+#             */
/*   Updated: 2026/05/08 03:44:55 by rogde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_KEY_STRUCT_H
# define T_KEY_STRUCT_H

# include "../../libft/libft.h"

typedef struct s_key
{
	int	w;
	int	s;
	int	a;
	int	d;
	int	left;
	int	right;
}	t_key;

t_key	*t_key_build(void);
void	t_key_debug(t_key *key);
void	t_key_destroy(t_key *key);
void	t_key_malloc_error(void);
void	t_key_struct_error(void);
int		t_key_populate(t_key **key_ref);

#endif
