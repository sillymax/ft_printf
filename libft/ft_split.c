/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 15:47:00 by ychng             #+#    #+#             */
/*   Updated: 2023/05/09 00:31:56 by ychng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	check_sep(char a, char b)
{
	if (a == b)
		return (1);
	return (0);
}

static	int	count_words(char *s, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] && check_sep(s[i], c))
			i++;
		if (s[i])
			count++;
		while (s[i] && !check_sep(s[i], c))
			i++;
	}
	return (count);
}

static	int	ft_strclen(char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && !check_sep(s[i], c))
		i++;
	return (i);
}

static	char	*add_word(char *s, char c)
{
	int		i;
	int		length;
	char	*word;

	length = ft_strclen(s, c);
	word = malloc(sizeof(char) * (length + 1));
	i = 0;
	while (i < length)
	{
		word[i] = s[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char	*char_s;
	char	**strs;
	int		strs_i;
	int		i;

	if (!s)
		return (NULL);
	char_s = (char *)s;
	strs = malloc(sizeof(char *) * (count_words(char_s, c) + 1));
	if (!strs)
		return (NULL);
	strs_i = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] && check_sep(s[i], c))
			i++;
		if (s[i])
			strs[strs_i++] = add_word(char_s + i, c);
		while (s[i] && !check_sep (s[i], c))
			i++;
	}
	strs[strs_i] = 0;
	return (strs);
}
