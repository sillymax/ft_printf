/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_uint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 15:20:49 by ychng             #+#    #+#             */
/*   Updated: 2023/06/10 23:00:00 by ychng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	uint_show_sign(t_result *result)
{
	if (result -> flags.show_sign)
		write(1, "+", 1);
	else if (result -> flags.space_flag)
		write(1, " ", 1);
	if (result -> flags.show_sign || result -> flags.space_flag)
	{
		(result -> length)++;
		return (1);
	}
	return (0);
}

void	uint_to_buf(unsigned int num, char *buffer, int *i, t_result *result)
{
	if (num == 0 && !(result -> specs.decimal))
	{
		buffer[0] = '0';
		buffer[1] = '\0';
		*i = 1;
		return ;
	}
	while (num)
	{
		buffer[(*i)++] = num % 10 + '0';
		num /= 10;
	}
	buffer[*i] = '\0';
}

void	n_left_justify(unsigned int num, char *buffer, int *i, t_result *result)
{
	int	temp;

	temp = 0;
	if (result -> flags.zero_pad && !(result -> specs.precision))
		uint_show_sign(result);
	if (num < 0 || result -> flags.show_sign || result -> flags.space_flag)
		temp = 1;
	if (result -> specs.precision > *i)
		temp += result -> specs.precision;
	else
		temp += *i;
	width_f(&temp, result);
	if (!(result -> flags.zero_pad) || result -> specs.precision)
		uint_show_sign(result);
	while ((result -> specs.precision)-- > *i)
	{
		write(1, "0", 1);
		(result -> length)++;
	}
	while ((*i)--)
	{
		write(1, &buffer[*i], 1);
		(result -> length)++;
	}
}

void	left_justify_uint(char *buffer, int *i, t_result *result)
{
	int	temp;

	temp = 0;
	if (result -> specs.precision > *i)
		temp += result -> specs.precision;
	else
		temp += *i;
	if (uint_show_sign(result))
		temp += 1;
	while ((result -> specs.precision)-- > *i)
	{
		write(1, "0", 1);
		(result -> length)++;
	}
	while ((*i)--)
	{
		write(1, &buffer[*i], 1);
		(result -> length)++;
	}
	while ((result -> specs.width)-- > temp)
	{
		write(1, " ", 1);
		(result -> length)++;
	}
}

void	print_uint(unsigned int num, t_result *result)
{
	char	buffer[11];
	int		i;

	i = 0;
	uint_to_buf(num, buffer, &i, result);
	if (result -> flags.left_justify)
		left_justify_uint(buffer, &i, result);
	else
		n_left_justify(num, buffer, &i, result);
}
