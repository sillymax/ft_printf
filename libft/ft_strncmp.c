/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 14:01:57 by ychng             #+#    #+#             */
/*   Updated: 2023/05/07 20:59:21 by ychng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t length)
{
	size_t			i;
	unsigned char	*char_s1;
	unsigned char	*char_s2;

	char_s1 = (unsigned char *)s1;
	char_s2 = (unsigned char *)s2;
	if (length == 0)
		return (0);
	i = 0;
	while (char_s1[i] && char_s2[i] && (i < (length - 1)))
	{
		if (char_s1[i] != char_s2[i])
			break ;
		i++;
	}
	return (char_s1[i] - char_s2[i]);
}
