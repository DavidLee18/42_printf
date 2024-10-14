/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehylee <jaehylee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 03:41:54 by jaehylee          #+#    #+#             */
/*   Updated: 2024/10/14 12:57:10 by jaehylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "../libft/libft.h"

int			ft_printf(const char *fmt, ...);

int			ft_vprintf(const char *fmt, va_list args);

int			fst_fmt_arg(const char *fmt);

int			is_fmt_arg(const char *str);

int			vprint_fmt(const char t, va_list args);

int			sum_or_error(const	int i, const int j, const int k);

int			vprint_chr(va_list args);

int			vprint_str(va_list args);

int			vprint_hex(va_list args);

int			vprint_hex_(va_list args);

int			vprint_int(va_list args);

int			vprint_uint(va_list args);

char		*ft_utoa(unsigned int u);

int			von_success(const int i, int (*f)(va_list), va_list args);

int			ft_ulog(const unsigned int base, const unsigned int n);

char		*ft_utox(unsigned int u);

char		*ft_utox_(unsigned int u);

#endif
