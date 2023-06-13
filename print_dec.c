/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_dec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 19:39:08 by ychng             #+#    #+#             */
/*   Updated: 2023/06/12 21:34:43 by ychng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	add_int_to_buf(int num, char *buffer, int *i, t_result *result)
{
	if (num == -2147483648)
	{
		min_val(buffer, i);
		return ;
	}
	if (num == 0 && !(result -> specs.decimal))
	{
		buffer[0] = '0';
		buffer[1] = '\0';
		*i = 1;
		return ;
	}
	if (num < 0)
		num *= -1;
	while (num)
	{
		buffer[(*i)++] = num % 10 + '0';
		num /= 10;
	}
	buffer[*i] = '\0';
}

void	print_dec(int num, t_result *result)
{
	char	buffer[11];
	int		i;

	i = 0;
	add_int_to_buf(num, buffer, &i, result);
	if (result -> flags.left_justify)
		left_justify(num, buffer, &i, result);
	else
		not_left_justify(num, buffer, &i, result);
}
