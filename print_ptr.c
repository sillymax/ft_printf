/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 20:43:51 by ychng             #+#    #+#             */
/*   Updated: 2023/06/10 22:37:29 by ychng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ptr_to_hex(uintptr_t num, t_result *result)
{
	int		rem;
	char	*hex;

	rem = 0;
	hex = "0123456789abcdef";
	if (num > 0)
	{
		rem = num % 16;
		ptr_to_hex(num / 16, result);
		write(1, &hex[rem], 1);
		(result -> length)++;
	}
}

void	ptr_precision(void *ptr, int *len, t_result *result)
{
	if (!result -> flags.zero_pad)
	{
		write(1, "0x", 2);
		(result -> length) += 2;
	}
	*len = 0;
	hex_to_len((uintptr_t)ptr, len);
	if (!(*len) && !result -> specs.decimal)
		*len += 1;
	while ((result -> specs.precision)-- > *len)
	{
		write(1, "0", 1);
		(result -> length)++;
	}
	if (!ptr && !result -> specs.decimal)
	{
		write(1, "0", 1);
		(result -> length)++;
	}
	else
		ptr_to_hex((uintptr_t)ptr, result);
}

void	ptr_not_justify(void *ptr, t_result *result)
{
	int	len;

	len = 2;
	hex_to_len((uintptr_t)ptr, &len);
	if (len == 2 && !result -> specs.decimal)
		len += 1;
	if (result -> flags.zero_pad && ((result -> specs.width) > len))
	{
		write(1, "0x", 2);
		(result -> length) += 2;
	}
	while ((result -> specs.width)-- > len)
	{
		if (result -> flags.zero_pad && !result -> specs.decimal)
			write(1, "0", 1);
		else
			write(1, " ", 1);
		(result -> length)++;
	}
	ptr_precision(ptr, &len, result);
}

void	ptr_justify(void *ptr, t_result *result)
{
	int	len;

	len = 0;
	hex_to_len((uintptr_t)ptr, &len);
	if (len == 2 && !result -> specs.decimal)
		len += 1;
	if (result -> flags.zero_pad && ((result -> specs.width) > len))
	{
		write(1, "0x", 2);
		(result -> length) += 2;
	}
	ptr_precision(ptr, &len, result);
	len = 2;
	hex_to_len((uintptr_t)ptr, &len);
	if (len == 2 && !result -> specs.decimal)
		len += 1;
	while ((result -> specs.width)-- > len)
	{
		if (result -> flags.zero_pad && !result -> specs.decimal)
			write(1, "0", 1);
		else
			write(1, " ", 1);
		(result -> length)++;
	}
}

void	print_ptr(void *ptr, t_result *result)
{
	if (result -> flags.left_justify)
		ptr_justify(ptr, result);
	else
		ptr_not_justify(ptr, result);
}
