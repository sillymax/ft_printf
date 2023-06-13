/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 19:36:03 by ychng             #+#    #+#             */
/*   Updated: 2023/05/07 20:46:56 by ychng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t length)
{
	size_t	i;
	char	*char_dest;
	char	*char_src;

	i = 0;
	char_dest = (char *)dest;
	char_src = (char *)src;
	if (!dest && !src)
		return (dest);
	if (dest > src)
	{
		while (length--)
			char_dest[length] = char_src[length];
	}
	else
	{
		i = 0;
		while (i < length)
		{
			char_dest[i] = char_src[i];
			i++;
		}
	}
	return (dest);
}
