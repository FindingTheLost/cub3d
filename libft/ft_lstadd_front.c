/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-alme <pde-alme@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 15:48:41 by pde-alme          #+#    #+#             */
/*   Updated: 2025/04/25 15:58:12 by pde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst != NULL && new != NULL)
	{
		new->next = *lst;
		*lst = new;
	}
}

/*int	main(void)
{
	t_list	**lst;
	t_list	*list;
	t_list	*new;
	char	*str1;
	char	*str2;

	str1 = malloc(2);
	str1[0] = 'A';
	str1[1] = '\0';

	str2 = malloc(2);
	str2[0] = 'B';
	str2[1] = '\0';

	list = ft_lstnew((void *)str1);
	new = ft_lstnew((void *)str2);

	lst = &list;

	printf("%s\n", (char *)(*lst)->content);
	ft_lstadd_front(lst, new);
	printf("%s\n", (char *)(*lst)->content);
	return (0);
}*/
