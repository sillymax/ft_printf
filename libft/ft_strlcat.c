/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 13:05:18 by ychng             #+#    #+#             */
/*   Updated: 2023/05/08 12:12:53 by ychng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t length)
{
	size_t	temp;
	size_t	dest_length;
	size_t	i;

	if (!length)
		return (ft_strlen(src));
	temp = ft_strlen(dest);
	dest_length = temp;
	i = 0;
	while (dest_length < (length - 1) && length && src[i])
		dest[dest_length++] = src[i++];
	dest[dest_length] = '\0';
	if (length > temp)
		return (temp + ft_strlen(src));
	return (length + ft_strlen(src));
}
