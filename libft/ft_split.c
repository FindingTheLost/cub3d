/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-alme <pde-alme@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 17:40:58 by pde-alme          #+#    #+#             */
/*   Updated: 2025/05/01 19:08:39 by pde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(char const *s, char c)
{
	unsigned int	index;
	unsigned int	num_words;
	unsigned int	on;

	index = 0;
	num_words = 0;
	on = 0;
	while (s[index] != '\0')
	{
		if (s[index] == c && on == 1)
		{
			on = 0;
			num_words++;
		}
		else if (s[index] != c)
			on = 1;
		index++;
	}
	if (on == 1)
		num_words++;
	return (num_words);
}

static size_t	get_letters(char const *s, char c, unsigned int pos)
{
	unsigned int	word;
	unsigned int	count;
	unsigned int	index;

	word = 0;
	count = 0;
	index = 0;
	while (s[index] == c && s[index] != '\0')
		index++;
	while (s[index] != '\0')
	{
		if (s[index++] == c)
		{
			while (s[index] == c)
				index++;
			word++;
			if (pos == word)
				return (count);
			count = 0;
			continue ;
		}
		count++;
	}
	return (count);
}

static char	*assign_chars(char const *s, char c, unsigned int pos, char *str)
{
	unsigned int	word;
	unsigned int	index;
	unsigned int	str_index;

	word = 0;
	index = 0;
	str_index = 0;
	while (s[index] == c)
		index++;
	while (word != pos)
	{
		if (s[index] == c)
		{
			while (s[index + 1] == c)
				index++;
			word++;
		}
		index++;
	}
	while (s[index] != c && s[index] != '\0')
		str[str_index++] = s[index++];
	str[str_index] = '\0';
	return (str);
}

static void	*free_array(char **split, unsigned int pos)
{
	unsigned int	index;

	index = 0;
	while (index < pos)
	{
		free(split[index]);
		index++;
	}
	free(split);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	unsigned int	index;
	char			**split;

	if (s == NULL)
		return (NULL);
	split = (char **)malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (split == NULL)
		return (NULL);
	index = 0;
	while (index < count_words(s, c))
	{
		split[index] = (char *)malloc(sizeof(char)
				* (get_letters(s, c, index + 1) + 1));
		if (split[index] == NULL)
			return (free_array(split, index));
		split[index] = assign_chars(s, c, index, split[index]);
		index++;
	}
	split[index] = NULL;
	return (split);
}

/*int	main(void)
{
	char	**split;
	char const	*s;
	char	c;

	s = "someword";
	c = 0;
	split = ft_split(s, c);
	printf("%s\n", split[0]);
	printf("%s\n", split[1]);
	//printf("%s\n", split[2]);
	return (0);
}*/
