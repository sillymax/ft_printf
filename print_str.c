/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 18:14:24 by ychng             #+#    #+#             */
/*   Updated: 2024/06/23 19:56:24 by ychng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	str_width(int *temp, t_result *result)
{
	while ((result -> specs.width)-- > *temp)
	{
		if (result -> flags.zero_pad)
			write(1, "0", 1);
		else
			write(1, " ", 1);
		(result -> length)++;
	}
}

void	str_not_justify(char *str, t_result *result)
{
	int	temp;
	int	i;

	temp = 0;
	if (!str)
		str = "(null)";
	if ((size_t)result -> specs.precision > ft_strlen(str))
		temp = ft_strlen(str);
	else if (result -> specs.decimal)
		temp = result -> specs.precision;
	else
		temp = ft_strlen(str);
	str_width(&temp, result);
	i = 0;
	while (i < temp)
	{
		write(1, &str[i++], 1);
		(result -> length)++;
	}
}

void	str_justify(char *str, t_result *result)
{
	int	temp;
	int	i;

	temp = 0;
	if (!str)
		str = "(null)";
	if ((size_t)result -> specs.precision > ft_strlen(str))
		temp = ft_strlen(str);
	else if (result -> specs.decimal)
		temp = result -> specs.precision;
	else
		temp = ft_strlen(str);
	i = 0;
	while (i < temp)
	{
		write(1, &str[i++], 1);
		(result -> length)++;
	}
	while ((result -> specs.width)-- > temp)
	{
		write(1, " ", 1);
		(result -> length)++;
	}
}

void	print_str(char *str, t_result *result)
{
	if (result -> flags.left_justify)
		str_justify(str, result);
	else
		str_not_justify(str, result);
}
