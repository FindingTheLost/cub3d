/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-alme <pde-alme@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 16:25:41 by pde-alme          #+#    #+#             */
/*   Updated: 2025/04/25 16:34:36 by pde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (lst == NULL || del == NULL)
		return ;
	del(lst->content);
	free(lst);
}

/*void	del(void *content)
{
	free(content);
}

int	main(void)
{
	char	*str;
	t_list	*node1;
	t_list	*node2;

	str = malloc(2);
	str[0] = 'A';
	str[1] = '\0';
	node1 = ft_lstnew((void *)str);
	node2 = ft_lstnew((void *)"B");
	node1->next = node2;
	printf("Node1 = %s\n", (char *)node1->content);
	printf("Node2 = %s\n", (char *)node2->content);
	ft_lstdelone(node1, &del);
	//printf("Node1 = %s\n", (char *)node1->content);
	printf("Node2 = %s\n", (char *)node2->content);
	return (0);
}*/
