/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_low_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 18:00:29 by ychng             #+#    #+#             */
/*   Updated: 2023/06/12 21:26:43 by ychng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	num_to_lhex(unsigned int num, t_result *result)
{
	int		rem;
	char	*hex;

	rem = 0;
	hex = "0123456789abcdef";
	if (num > 0)
	{
		rem = num % 16;
		num_to_lhex(num / 16, result);
		write(1, &hex[rem], 1);
		(result -> length)++;
	}
}

void	lhex_precision(unsigned int num, int *len, t_result *result)
{
	if (!result -> flags.zero_pad && result -> flags.alternate && num)
	{
		write(1, "0x", 2);
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
		num_to_lhex(num, result);
}

void	lhex_not_justify(unsigned int num, t_result *result)
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
		write(1, "0x", 2);
		(result -> length) += 2;
	}
	if (precision > len)
		len = precision;
	hex_width(&len, result);
	lhex_precision(num, &len, result);
}

void	lhex_justify(unsigned int num, t_result *result)
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
		write(1, "0x", 2);
		(result -> length) += 2;
	}
	lhex_precision(num, &len, result);
	if (precision > len)
		len = precision;
	hex_width(&len, result);
}

void	print_low_hex(unsigned int num, t_result *result)
{
	if (result -> flags.left_justify)
		lhex_justify(num, result);
	else
		lhex_not_justify(num, result);
}
