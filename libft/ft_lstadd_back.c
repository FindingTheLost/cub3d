/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-alme <pde-alme@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 16:13:49 by pde-alme          #+#    #+#             */
/*   Updated: 2025/05/01 17:25:30 by pde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;

	if (lst == NULL || new == NULL)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	temp = ft_lstlast(*lst);
	temp->next = new;
}

/*int	main(void)
{
	t_list	*node1;
	t_list	*node2;
	t_list	*node3;
	t_list	*new;
	t_list	**lst;

	node1 = ft_lstnew(NULL);
	node2 = ft_lstnew(NULL);
	node3 = ft_lstnew(NULL);
	new = ft_lstnew(NULL);

	node1->next = node2;
	node2->next = node3;
	printf("%i\n", ft_lstsize(node1));

	lst = &node1;
	ft_lstadd_back(lst, new);
	printf("%i\n", ft_lstsize(node1));
	return (0);
}*/
