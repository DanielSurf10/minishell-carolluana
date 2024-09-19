/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 21:07:34 by cshingai          #+#    #+#             */
/*   Updated: 2023/11/07 14:42:59 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	cont_words(const char *s, char sep)
{
	int	nbr_word;

	nbr_word = 0;
	while (*s)
	{
		if (*s != sep && (*(s + 1) == sep || *(s + 1) == '\0'))
			nbr_word++;
		s++;
	}
	return (nbr_word);
}

int	words_len(char const *s, char sep)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != sep)
		i++;
	return (i);
}

void	ft_free_big_str(char **big_str, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		free(big_str[i]);
		i++;
	}
	free(big_str);
}

char	*ft_put_words_in_array(const char *s, char sep)
{
	int		idx_s;
	int		i;
	int		word_size;
	char	*new_word;

	idx_s = 0;
	i = -1;
	if (s[0] == '\0')
		return (0);
	while (s[idx_s] && s[idx_s] == sep)
		idx_s++;
	if (s[idx_s])
	{
		word_size = words_len(s + idx_s, sep);
		new_word = (char *) malloc((word_size + 1) * sizeof(char));
		if (!new_word)
			return (0);
		while (++i < word_size)
			new_word[i] = s[idx_s + i];
		new_word[words_len(s + idx_s, sep)] = '\0';
	}
	if (s[idx_s] == '\0' || !new_word)
		return (0);
	return (new_word);
}

char	**ft_split(char const *s, char c)
{
	char	**big_str;
	int		word_count;
	int		iter_word;

	iter_word = 0;
	word_count = cont_words(s, c);
	big_str = (char **) malloc (sizeof(char *) * (word_count + 1));
	if (!s)
		return (0);
	while (iter_word <= word_count)
	{
		big_str[iter_word] = ft_put_words_in_array(s, c);
		if (iter_word != word_count && !big_str[iter_word])
		{
			ft_free_big_str(big_str, word_count);
			return (0);
		}
		while (*s == c)
			s++;
		if (*s != '\0')
			s += words_len(s, c);
		iter_word++;
	}
	return (big_str);
}
