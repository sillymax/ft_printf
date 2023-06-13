/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 14:27:42 by ychng             #+#    #+#             */
/*   Updated: 2023/06/12 21:34:36 by ychng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	zeroize_result(t_result *result)
{
	result -> temp = 0;
	result -> flags.left_justify = 0;
	result -> flags.show_sign = 0;
	result -> flags.space_flag = 0;
	result -> flags.alternate = 0;
	result -> flags.zero_pad = 0;
	result -> specs.width = 0;
	result -> specs.decimal = 0;
	result -> specs.precision = 0;
}

void	hex_to_len(uintptr_t num, int *len)
{
	if (num > 0)
	{
		hex_to_len(num / 16, len);
		(*len)++;
	}
}

void	width_f(int *temp, t_result *result)
{
	while ((result -> specs.width)-- > *temp)
	{
		if (result -> flags.zero_pad && !(result -> specs.decimal))
			write(1, "0", 1);
		else
			write(1, " ", 1);
		(result -> length)++;
	}
}

void	num_to_len(unsigned int num, int *len)
{
	if (num > 0)
	{
		hex_to_len(num / 16, len);
		(*len)++;
	}
}

void	hex_width(int *len, t_result *result)
{
	while (((result -> specs.width)-- > *len))
	{
		if (result -> flags.zero_pad && !result -> specs.decimal)
			write(1, "0", 1);
		else
			write(1, " ", 1);
		(result -> length)++;
	}
}
