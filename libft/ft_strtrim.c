/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-alme <pde-alme@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 14:45:18 by pde-alme          #+#    #+#             */
/*   Updated: 2025/05/01 17:45:36 by pde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	rev_check_string(char const *s1, char const *set)
{
	unsigned int	index;
	unsigned int	set_index;

	if (ft_strlen((char *)s1) == 0)
		return (0);
	index = ft_strlen((char *)s1) - 1;
	set_index = 0;
	while (set[set_index] != '\0')
	{
		if (s1[index] == set[set_index])
		{
			if (index == 0)
				break ;
			index--;
			set_index = 0;
		}
		else
			set_index++;
	}
	return (index);
}

static size_t	check_string(char const *s1, char const *set)
{
	unsigned int	index;
	unsigned int	set_index;

	if (ft_strlen((char *)s1) == 0)
		return (0);
	index = 0;
	set_index = 0;
	while (set[set_index] != '\0')
	{
		if (s1[index] == set[set_index])
		{
			index++;
			set_index = 0;
		}
		else
			set_index++;
	}
	return (index);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	unsigned int	start;
	unsigned int	end;
	unsigned int	index;
	char			*ptr;

	if (s1 == NULL || set == NULL)
		return (NULL);
	start = check_string(s1, set);
	end = rev_check_string(s1, set);
	if (ft_strlen((char *)s1) == 0)
		start = 1;
	if (start > end)
		ptr = (char *)malloc(sizeof(char));
	else
		ptr = (char *)malloc((sizeof(char) * ((end + 1) - start)) + 1);
	if (ptr == NULL)
		return (NULL);
	index = 0;
	while (start <= end)
		ptr[index++] = s1[start++];
	ptr[index] = '\0';
	return (ptr);
}

/*int	main(void)
{
	char	*s1;
	char	*set;

	s1 = "asdHELLOasdi";
	set = "asdHELLO"; 
	printf("%s\n", ft_strtrim(s1, set));
	return (0);
}*/
