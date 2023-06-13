/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 17:25:32 by ychng             #+#    #+#             */
/*   Updated: 2023/05/08 11:57:55 by ychng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *substr, size_t length)
{	
	size_t	i;
	size_t	j;

	if (!str && !length)
		return (NULL);
	i = 0;
	if (!substr[i])
		return ((char *)str + i);
	while (str[i] && (i < length))
	{
		j = 0;
		while (substr[j])
		{
			if ((str[i + j] == substr[j]) && ((i + j) < length))
			{
				j++;
				if (!substr[j])
					return ((char *)str + i);
			}
			else
				break ;
		}
		i++;
	}
	return (NULL);
}
