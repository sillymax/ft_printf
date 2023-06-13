/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 19:38:32 by ychng             #+#    #+#             */
/*   Updated: 2023/05/06 18:39:24 by ychng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int	i;
	int	j;
	int	flag;

	i = 0;
	j = 0;
	flag = 0;
	while (str[i])
	{
		if (str[i] == (char)c)
		{
			j = i;
			flag = 1;
		}
		i++;
	}
	if (flag)
		return ((char *)str + j);
	else if (c == '\0')
		return ((char *)str + i);
	else
		return (NULL);
}
