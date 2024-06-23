/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_format.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 15:43:12 by ychng             #+#    #+#             */
/*   Updated: 2024/06/23 19:56:03 by ychng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	min_val(char *buffer, int *i)
{
	int	j;

	j = 0;
	while (j < 10)
	{
		buffer[j] = "8463847412"[j];
		j++;
	}
	buffer[10] = '\0';
	*i = 10;
}

int	show_sign(int num, t_result *result)
{
	if (num < 0)
		write(1, "-", 1);
	else if (result -> flags.show_sign)
		write(1, "+", 1);
	else if (result -> flags.space_flag)
		write(1, " ", 1);
	if (num < 0 || result -> flags.show_sign || result -> flags.space_flag)
	{
		(result -> length)++;
		return (1);
	}
	return (0);
}

void	not_left_justify(int num, char *buffer, int *i, t_result *result)
{
	int	temp;

	temp = 0;
	if (result -> flags.zero_pad && !(result -> specs.precision))
		show_sign(num, result);
	if (num < 0 || result -> flags.show_sign || result -> flags.space_flag)
		temp = 1;
	if (result -> specs.precision > *i)
		temp += result -> specs.precision;
	else
		temp += *i;
	width_f(&temp, result);
	if (!(result -> flags.zero_pad) || result -> specs.precision)
		show_sign(num, result);
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

void	left_justify(int num, char *buffer, int *i, t_result *result)
{
	int	temp;

	temp = 0;
	if (result -> specs.precision > *i)
		temp += result -> specs.precision;
	else
		temp += *i;
	if (show_sign(num, result))
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
