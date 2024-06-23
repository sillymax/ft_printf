/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 16:36:18 by ychng             #+#    #+#             */
/*   Updated: 2024/06/23 19:55:53 by ychng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	check_flag(char *str, int *i, t_result *result)
{
	while (str[*i] == '-' || str[*i] == '+'
		|| str[*i] == ' ' || str[*i] == '#' || str[*i] == '0')
	{
		if (str[*i] == '-')
			result -> flags.left_justify = 1;
		else if (str[*i] == '+')
			result -> flags.show_sign = 1;
		else if (str[*i] == ' ')
			result -> flags.space_flag = 1;
		else if (str[*i] == '#')
			result -> flags.alternate = 1;
		else if (str[*i] == '0')
			result -> flags.zero_pad = 1;
		(*i)++;
	}
}

void	check_specs(char *str, int *i, t_result *result)
{
	int		j;
	char	buffer[12];

	while ((str[*i] >= '0' && str[*i] <= '9') || str[*i] == '.')
	{
		j = 0;
		while (str[*i] == '.')
		{
			result -> specs.decimal = 1;
			(*i)++;
		}
		while (str[*i] >= '0' && str[*i] <= '9')
			buffer[j++] = str[(*i)++];
		buffer[j] = '\0';
		if (!(result -> specs.decimal))
			result -> specs.width = ft_atoi(buffer);
		else
		{
			result -> specs.precision = ft_atoi(buffer);
			break ;
		}
	}
	while (str[*i] == '.')
		(*i)++;
}

void	check_format(char *str, int *i, va_list ap, t_result *result)
{
	if (str[*i] == 'c')
		print_char(va_arg(ap, int), result);
	if (str[*i] == 's')
		print_str(va_arg(ap, char *), result);
	if (str[*i] == 'p')
		print_ptr(va_arg(ap, void *), result);
	if (str[*i] == 'd' || str[*i] == 'i')
		print_dec(va_arg(ap, int), result);
	if (str[*i] == 'u')
		print_uint(va_arg(ap, unsigned int), result);
	if (str[*i] == 'x')
		print_low_hex(va_arg(ap, unsigned int), result);
	if (str[*i] == 'X')
		print_upp_hex(va_arg(ap, unsigned int), result);
	if (str[*i] == '%')
		print_percent(result);
	(*i)++;
}

void	parse_str(char *str, va_list ap, t_result *result)
{
	int		i;

	i = 0;
	while (str[i])
	{
		while (str[i] == '%')
		{
			i++;
			check_flag(str, &i, result);
			check_specs(str, &i, result);
			check_format(str, &i, ap, result);
			zeroize_result(result);
		}
		if (!str[i])
			break ;
		write(1, &str[i], 1);
		(result -> length)++;
		i++;
	}
}

int	ft_printf(const char *str, ...)
{
	t_result	result;
	va_list		ap;

	va_start(ap, str);
	result.length = 0;
	zeroize_result(&result);
	parse_str((char *)str, ap, &result);
	va_end(ap);
	return (result.length);
}
