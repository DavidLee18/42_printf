/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehylee <jaehylee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 00:17:11 by jaehylee          #+#    #+#             */
/*   Updated: 2024/10/12 00:17:11 by jaehylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *fmt, ...)
{
	va_list	args;
	int		res;

	if (!fmt || !*fmt)
		return (-1);
	va_start(args, fmt);
	res = ft_vprintf(fmt, args);
	va_end(args);
	return (res);
}

int	ft_vprintf(const char *fmt, va_list args)
{
	int			arg_idx;
	int			flag;
	int			flag2;
	int			flag3;

	arg_idx = fst_fmt_arg(fmt);
	if (arg_idx < 0)
		return ((int)write(STDOUT_FILENO, fmt, ft_strlen(fmt)));
	flag = (int)write(STDOUT_FILENO, fmt, arg_idx);
	if (flag < 0)
		return (flag);
	flag2 = vprint_fmt(fmt[arg_idx + 1], args);
	if (flag2 < 0)
		return (flag2);
	if (fmt[arg_idx + 2])
		return (sum_or_error(flag, flag2, ft_vprintf(fmt + arg_idx + 2, args)));
	else
		return (flag + flag2);
}

int	is_fmt_arg(const char *str)
{
	return (str[0] == '%' && (str[1] == 'c' || str[1] == 's'
			|| str[1] == 'p' || str[1] == 'd' || str[1] == 'i'
			|| str[1] == 'u' || str[1] == 'x' || str[1] == 'X'
			|| str[1] == '%'));
}

int	fst_fmt_arg(const char *fmt)
{
	int			i;

	if (!fmt)
		return (-1);
	i = -1;
	while (fmt[++i])
	{
		if (is_fmt_arg(fmt + i))
			return (i);
	}
	return (-1);
}

int	sum_or_error(const int i, const int j, const int k)
{
	if (k < 0)
		return (k);
	return (i + j + k);
}
