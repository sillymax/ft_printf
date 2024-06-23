/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_upp_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 18:00:29 by ychng             #+#    #+#             */
/*   Updated: 2024/06/23 19:56:30 by ychng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	num_to_uhex(unsigned int num, t_result *result)
{
	int		rem;
	char	*hex;

	rem = 0;
	hex = "0123456789ABCDEF";
	if (num > 0)
	{
		rem = num % 16;
		num_to_uhex(num / 16, result);
		write(1, &hex[rem], 1);
		(result -> length)++;
	}
}

void	uhex_precision(unsigned int num, int *len, t_result *result)
{
	if (!result -> flags.zero_pad && result -> flags.alternate && num)
	{
		write(1, "0X", 2);
		(result -> length) += 2;
	}
	*len = 0;
	num_to_len(num, len);
	if (!(*len) && !result -> specs.decimal)
		*len += 1;
	while ((result -> specs.precision)-- > *len)
	{
		write(1, "0", 1);
		(result -> length)++;
	}
	if (!num && !result -> specs.decimal)
	{
		write(1, "0", 1);
		(result -> length)++;
	}
	else
		num_to_uhex(num, result);
}

void	uhex_not_justify(unsigned int num, t_result *result)
{
	int	len;
	int	precision;

	len = 0;
	precision = result -> specs.precision;
	if (!num && !result -> specs.decimal && !result -> specs.precision)
		len = 1;
	if (result -> flags.alternate && num)
		len += 2;
	num_to_len(num, &len);
	if (len == 2 && !result -> specs.decimal
		&& result -> flags.alternate)
		len += 1;
	if (result -> flags.zero_pad && result -> flags.alternate && num)
	{
		write(1, "0X", 2);
		(result -> length) += 2;
	}
	if (precision > len)
		len = precision;
	hex_width(&len, result);
	uhex_precision(num, &len, result);
}

void	uhex_justify(unsigned int num, t_result *result)
{
	int	len;
	int	precision;

	len = 0;
	precision = result -> specs.precision;
	if (!num && !result -> specs.decimal && !result -> specs.precision)
		len = 1;
	if (result -> flags.alternate && num)
		len += 2;
	num_to_len(num, &len);
	if (len == 2 && !result -> specs.decimal
		&& result -> flags.alternate)
		len += 1;
	if (result -> flags.zero_pad && result -> flags.alternate && num)
	{
		write(1, "0X", 2);
		(result -> length) += 2;
	}
	uhex_precision(num, &len, result);
	if (precision > len)
		len = precision;
	hex_width(&len, result);
}

void	print_upp_hex(unsigned int num, t_result *result)
{
	if (result -> flags.left_justify)
		uhex_justify(num, result);
	else
		uhex_not_justify(num, result);
}
