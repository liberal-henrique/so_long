/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lliberal <lliberal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 12:44:49 by lliberal          #+#    #+#             */
/*   Updated: 2023/03/16 12:45:05 by lliberal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	write_word(char *dest, const char *from, char set)
{
	int	i;

	i = 0;
	while (from[i] != '\0')
	{
		if (from[i] != set)
			dest[i] = from[i];
		if (from[i] == set)
			break ;
		i++;
	}
	dest[i] = '\0';
	return (*dest);
}

int	word_count(const char *sr, char del)
{
	int	j;
	int	word;

	j = 0;
	word = 0;
	while (sr[j])
	{
		if (sr[j] != del && ((sr[j + 1] == del) || (sr[j + 1] == '\0')))
			word++;
		j++;
	}
	return (word);
}

void	add_split(char **dst, const char *string, char delimiter)
{
	int	l;
	int	j;
	int	letter;

	l = 0;
	letter = 0;
	while (string[l])
	{
		if (string[l] == delimiter)
			l++;
		else
		{
			j = 0;
			while (string[l + j] != delimiter && string[j + l])
				j++;
			dst[letter] = malloc (sizeof(char) * (j + 1));
			if (!dst[letter])
				return ;
			write_word(dst[letter], string + l, delimiter);
			if (string[j + l] == '\0')
				break ;
			l = l + j;
			letter++;
		}
	}
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		words;

	if (!s)
		return (NULL);
	words = word_count(s, c);
	res = malloc (sizeof(char *) * (words + 1));
	if (!res)
		return (NULL);
	res[words] = NULL;
	add_split(res, s, c);
	return (res);
}
