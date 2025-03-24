/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehylee <jaehylee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 00:17:11 by jaehylee          #+#    #+#             */
/*   Updated: 2025/03/24 16:08:35 by jaehylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_fprintf(const int fd, const char *fmt, ...)
{
	va_list	args;
	int		res;
	t_list	*dyn;

	if (!fmt || !*fmt)
		return (-1);
	dyn = NULL;
	va_start(args, fmt);
	res = ft_vprintf(&dyn, fd, fmt, args);
	va_end(args);
	return (gc_free_all(dyn), res);
}

int	ft_vprintf(t_list **dyn, const int fd, const char *fmt, va_list args)
{
	t_fmt_arg	*arg;
	int			flag;
	int			flag2;

	arg = fst_fmt_arg(dyn, fmt);
	if (!arg)
		return ((int)write(fd, fmt, ft_strlen(fmt)));
	flag = (int)write(fd, fmt, arg->start);
	if (flag < 0)
		return (flag);
	flag2 = vprint_fmt(dyn, fd, arg, args);
	if (flag2 < 0)
		return (flag2);
	if (fmt[arg->end + 1])
		return (sum_or_error(flag, flag2,
				ft_vprintf(dyn, fd, fmt + arg->end + 1, args)));
	return (flag + flag2);
}

t_fmt_arg	*fst_fmt_arg(t_list **dyn, const char *fmt)
{
	size_t		i;
	t_fmt_arg	*res;
	_Bool		j;

	i = 0;
	while (fmt[i] && fmt[i] != '%')
		i++;
	if (!fmt[i])
		return (NULL);
	res = init_fmt_arg(dyn);
	if (!res)
		return (NULL);
	res->start = i++;
	preproc_flags(dyn, fmt, res, &i);
	parse_width(dyn, fmt, res, &i);
	parse_prec(dyn, fmt, res, &i);
	j = parse_conv_spec(fmt, res, i);
	res->end = i;
	if (j == 1)
		return (res);
	return (NULL);
}

int	sum_or_error(const int i, const int j, const int k)
{
	if (k < 0)
		return (k);
	return (i + j + k);
}

_Bool	parse_conv_spec(const char *fmt, t_fmt_arg *arg, const size_t i)
{
	if (!is_conv_spec(fmt[i]))
		return (0);
	arg->conv_spec = fmt[i];
	return (1);
}
