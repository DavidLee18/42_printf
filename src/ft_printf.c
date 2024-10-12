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
	int			*arg_idx;
	int			flag;
	int			flag2;
	int			flag3;
	int			new_idx;

	arg_idx = fst_fmt_arg(fmt);
	if (!arg_idx)
		return ((int)write(STDOUT_FILENO, fmt, ft_strlen(fmt)));
	flag = (int)write(STDOUT_FILENO, fmt, *arg_idx);
	new_idx = *arg_idx + 2;
	free(arg_idx);
	if (flag < 0)
		return (flag);
	flag2 = print_fmt(fmt[new_idx - 1]);
	if (flag2 < 0)
		return (flag2);
	if (fmt[new_idx])
		return (sum_or_error(flag, flag2, ft_vprintf(fmt + new_idx, args)));
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

int	*fst_fmt_arg(const char *fmt)
{
	int			*res;
	int			i;

	if (!fmt)
		return (NULL);
	i = -1;
	while (fmt[++i])
	{
		if (is_fmt_arg(fmt + i))
		{
			res = (int *)malloc(sizeof(int));
			if (!res)
				return (NULL);
			*res = i;
			return (res);
		}
	}
	return (NULL);
}
