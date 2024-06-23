/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_percent.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 18:52:43 by ychng             #+#    #+#             */
/*   Updated: 2024/06/23 19:56:15 by ychng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	percent_not_justify(t_result *result)
{
	while ((result -> specs.width)-- > 1)
	{
		if (result -> flags.zero_pad)
			write(1, "0", 1);
		else
			write(1, " ", 1);
		(result -> length)++;
	}
	write(1, "%", 1);
	(result -> length)++;
}

void	percent_justify(t_result *result)
{
	write(1, "%", 1);
	(result -> length)++;
	while ((result -> specs.width)-- > 1)
	{
		write(1, " ", 1);
		(result -> length)++;
	}
}

void	print_percent(t_result *result)
{
	if (result -> flags.left_justify)
		percent_justify(result);
	else
		percent_not_justify(result);
}
