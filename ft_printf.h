/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 16:32:28 by ychng             #+#    #+#             */
/*   Updated: 2024/06/23 20:12:51 by ychng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdint.h>
# include <stdarg.h>
# include <unistd.h>
# include "libft/libft.h"

typedef struct format_flags
{
	int	left_justify;
	int	show_sign;
	int	space_flag;
	int	alternate;
	int	zero_pad;
}	t_flags;

typedef struct format_specs
{
	int	width;
	int	decimal;
	int	precision;
}	t_specs;

typedef struct result_info
{
	const char		*result;
	int				length;
	int				temp;
	t_flags			flags;
	t_specs			specs;
}	t_result;

// ft_printf.c
int		ft_printf(const char *str, ...);

void	print_char(char c, t_result *result);
void	print_str(char *str, t_result *result);
void	print_ptr(void *ptr, t_result *result);
void	print_dec(int num, t_result *result);
void	print_uint(unsigned int num, t_result *result);
void	print_low_hex(unsigned int num, t_result *result);
void	print_upp_hex(unsigned int num, t_result *result);
void	print_percent(t_result *result);

// print_dec.c
// int_format.c
void	min_val(char *buffer, int *i);
void	not_left_justify(int num, char *buffer, int *i, t_result *result);
int		show_sign(int num, t_result *result);
void	left_justify(int num, char *buffer, int *i, t_result *result);

// functions.c
// printf.c
void	zeroize_result(t_result *result);
// print_ptr.c
void	hex_to_len(uintptr_t num, int *len);
// print_dec.c
void	add_int_to_buf(int num, char *buffer, int *i, t_result *result);
// print_uint.c
void	width_f(int *temp, t_result *result);
// print_low_hex.c
// print_upp_hex.c
void	num_to_len(unsigned int num, int *len);
void	hex_width(int *len, t_result *result);

#endif
