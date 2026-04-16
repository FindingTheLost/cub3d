/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-alme <pde-alme@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 17:57:23 by pde-alme          #+#    #+#             */
/*   Updated: 2025/04/25 19:37:08 by pde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*void	del(void *content)
{
	free(content);
}

void	*f(void *content)
{
	char	*conv;

	conv = content;
	conv[0] += 1;
	return ((void *)conv);
}*/

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*new_lst_cpy;

	if (lst == NULL || f == NULL || del == NULL)
		return (NULL);
	new_lst = ft_lstnew(f(lst->content));
	if (new_lst == NULL)
		return (NULL);
	new_lst_cpy = new_lst;
	lst = lst->next;
	while (lst != NULL)
	{
		new_lst->next = ft_lstnew(f(lst->content));
		if (new_lst->next == NULL)
		{
			ft_lstclear(&new_lst_cpy, del);
			return (NULL);
		}
		new_lst = new_lst->next;
		lst = lst->next;
	}
	return (new_lst_cpy);
}

/*int	main(void)
{
	t_list	*node1;
	t_list	*node2;
	t_list	*node3;
	t_list	*new_lst;
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

	printf("List: %s, %s and %s\n", (char *)node1->content,
			(char *)node2->content, (char *)node3->content);
	new_lst = ft_lstmap(node1, &f, &del);
	printf("New List: %s, %s and %s\n", (char *)new_lst->content,
			(char *)(new_lst->next)->content,
				(char *)((new_lst->next)->next)->content);
	printf("List (after change): %s, %s and %s\n", (char *)node1->content,
			(char *)node2->content, (char *)node3->content);
	return (0);
}*/
