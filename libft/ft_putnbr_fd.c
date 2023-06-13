/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 17:10:59 by ychng             #+#    #+#             */
/*   Updated: 2023/05/06 15:18:17 by ychng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	add_into_temp(long n, char *temp)
{
	int		i;
	long	just_n;

	just_n = n;
	i = 0;
	if (n == 0)
		temp[i++] = '0';
	if (n < 0)
		n *= -1;
	while (n)
	{
		temp[i] = n % 10 + '0';
		i++;
		n /= 10;
	}
	if (just_n < 0)
		temp[i++] = '-';
	temp[i] = '\0';
}

static void	ft_reverse(char *temp, char *result)
{
	int		i;
	int		length;

	length = ft_strlen(temp);
	i = 0;
	while (length--)
		result[i++] = temp[length];
	result[i] = '\0';
}

static void	write_to_fd(int fd, char *result)
{
	int	i;

	i = 0;
	while (result[i])
	{
		write(fd, &result[i], 1);
		i++;
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	char	temp[16384];
	char	result[16384];

	add_into_temp(n, temp);
	ft_reverse(temp, result);
	write_to_fd(fd, result);
}
