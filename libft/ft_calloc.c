/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 19:28:05 by ychng             #+#    #+#             */
/*   Updated: 2023/05/08 12:02:52 by ychng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nItems, size_t sizeOf)
{
	void	*ptr;

	if (nItems == SIZE_MAX)
		return (NULL);
	ptr = malloc(nItems * sizeOf);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, nItems * sizeOf);
	return (ptr);
}
