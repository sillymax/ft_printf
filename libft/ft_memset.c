/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 17:55:16 by ychng             #+#    #+#             */
/*   Updated: 2023/05/07 20:39:17 by ychng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *buffer, int c, size_t length)
{
	size_t	i;
	char	*char_buffer;

	char_buffer = (char *)buffer;
	if (!buffer && !c)
		return (NULL);
	i = 0;
	while (i < length)
	{
		char_buffer[i] = c;
		i++;
	}
	return (buffer);
}
