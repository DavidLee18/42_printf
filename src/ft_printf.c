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
	t_fmt_arg	*arg;
	int			flag;
	int			flag2;

	arg = fst_fmt_arg(fmt);
	if (!arg)
		return ((int)write(STDOUT_FILENO, fmt, ft_strlen(fmt)));
	flag = (int)write(STDOUT_FILENO, fmt, arg->start);
	if (flag < 0)
		return (free_and_return(arg, flag));
	flag2 = vprint_fmt(*arg, args);
	if (flag2 < 0)
		return (free_and_return(arg, flag2));
	if (fmt[arg->end + 1])
		return (free_and_return(arg, sum_or_error(flag, flag2,
				ft_vprintf(fmt + arg->end + 1, args))));
	else
		return (free_and_return(arg, flag + flag2));
}

t_fmt_arg	*fst_fmt_arg(const char *fmt)
{
	size_t		i;
	t_fmt_arg	*res;

	if (!fmt)
		return (NULL);
	i = 0;
	while (fmt[i] && fmt[i] != '%')
		i++;
	if (!fmt[i])
		return (NULL);
	res = (t_fmt_arg *)ft_calloc(1, sizeof(t_fmt_arg));
	if (!res)
		return (NULL);
	res->start = i++;
	preproc_flags(fmt, res, &i);
	// ...
	return (res);
}

int	sum_or_error(const int i, const int j, const int k)
{
	if (k < 0)
		return (k);
	return (i + j + k);
}
