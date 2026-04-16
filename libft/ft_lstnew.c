/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-alme <pde-alme@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 15:39:16 by pde-alme          #+#    #+#             */
/*   Updated: 2025/04/25 15:47:53 by pde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*ptr;

	ptr = (t_list *)malloc(sizeof(t_list));
	if (ptr == NULL)
		return (NULL);
	ptr->content = content;
	ptr->next = NULL;
	return (ptr);
}

/*int	main(void)
{
	char	*str;
	t_list	*list;

	str = malloc(4);
	str[0] = 'O';
	str[1] = 'L';
	str[2] = 'A';
	str[3] = '\0';
	list = ft_lstnew((void *)str);
	printf("%s and %s\n", (char *)list->content, (char *)list->next);
	return (0);
}*/
