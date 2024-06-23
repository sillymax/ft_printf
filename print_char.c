/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 17:25:12 by ychng             #+#    #+#             */
/*   Updated: 2024/06/23 19:56:07 by ychng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_char(char c, t_result *result)
{
	int	i;

	i = 0;
	if (result -> flags.left_justify)
	{
		write(1, &c, 1);
		(result -> length)++;
	}
	while (i < ((result -> specs.width) - 1))
	{
		if (!(result -> flags.left_justify) && result -> flags.zero_pad)
			write(1, "0", 1);
		else
			write(1, " ", 1);
		(result -> length)++;
		i++;
	}
	if (!(result -> flags.left_justify))
	{
		write(1, &c, 1);
		(result -> length)++;
	}
}
