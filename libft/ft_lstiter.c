/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-alme <pde-alme@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 17:25:31 by pde-alme          #+#    #+#             */
/*   Updated: 2025/04/25 17:56:24 by pde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*void	f(void *content)
{
	char	*conv;

	conv = content;
	conv[0] = conv[0] + 1;
}*/

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (lst == NULL || f == NULL)
		return ;
	while (lst->next != NULL)
	{
		f(lst->content);
		lst = lst->next;
	}
	f(lst->content);
}

/*int	main(void)
{
	t_list	*node1;
	t_list	*node2;
	t_list	*node3;
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
	printf("%s, %s and %s\n", (char *)node1->content,
			(char *)node2->content, (char *)node3->content);
	ft_lstiter(node1, &f);
	printf("%s, %s and %s\n", (char *)node1->content,
			(char *)node2->content, (char *)node3->content);
	return (0);
}*/
