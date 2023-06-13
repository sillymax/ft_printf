/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 15:44:48 by ychng             #+#    #+#             */
/*   Updated: 2023/05/07 20:54:06 by ychng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t length)
{
	size_t			i;
	unsigned char	*char_str;
	unsigned char	char_c;

	char_str = (unsigned char *)str;
	char_c = (unsigned char)c;
	i = 0;
	while (i < length)
	{
		if (char_str[i] == char_c)
			return ((void *)str + i);
		i++;
	}
	return (NULL);
}
