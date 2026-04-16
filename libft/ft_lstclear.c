/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-alme <pde-alme@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 16:37:06 by pde-alme          #+#    #+#             */
/*   Updated: 2025/05/01 17:06:15 by pde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*void	del(void *content)
{
	free(content);
}*/

static void	free_node(t_list *list, void (*del)(void *))
{
	if (list->next != NULL)
		free_node(list->next, del);
	del(list->content);
	free(list);
}

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	if (lst == NULL || del == NULL)
		return ;
	free_node(*lst, del);
	*lst = NULL;
}

/*int	main(void)
{
	t_list	*node1;
	t_list	*node2;
	t_list	*node3;
	t_list	**lst;
	char	*str1;
	char	*str2;
	char	*str3;

	str1 = malloc(2);
	str2 = malloc(2);
	str3 = malloc(2);
	str1[0] = 'A';
	str1[1] = '\0';
	str2[0] = 'B';
	str2[1] = '\0';
	str3[0] = 'C';
	str3[1] = '\0';

	node1 = ft_lstnew((void *)str1);
	node2 = ft_lstnew((void *)str2);
	node3 = ft_lstnew((void *)str3);
	node1->next = node2;
	node2->next = node3;
	lst = &node1;

	printf("%s, %s and %s\n", (char *)node1->content,
			(char *)node2->content, (char *)node3->content);
	ft_lstclear(lst, &del);
	//printf("%s\n", (char *)node1->content);
	//printf("%s\n", (char *)node2->content);
	//printf("%s\n", (char *)node3->content);
	return (0);
}*/
