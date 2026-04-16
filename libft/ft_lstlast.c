/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-alme <pde-alme@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 16:06:16 by pde-alme          #+#    #+#             */
/*   Updated: 2025/04/25 16:13:11 by pde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

/*int	main(void)
{
	char	*str1;
	char	*str2;
	char	*str3;
	t_list	*node1;
	t_list	*node2;
	t_list	*node3;

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

	printf("%s\n", (char *)(ft_lstlast(node1))->content);
	return (0);
}*/
