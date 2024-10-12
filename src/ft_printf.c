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
	t_arg_type	*arg;

	arg = fst_fmt_arg(fmt);
	if (!arg)
		return ((int)write(STDOUT_FILENO, fmt, ft_strlen(fmt)));

}

int	is_fmt_arg(const char *str)
{
	return (str[0] == '%' && (str[1] == 'c' || str[1] == 's'
			|| str[1] == 'p' || str[1] == 'd' || str[1] == 'i'
			|| str[1] == 'u' || str[1] == 'x' || str[1] == 'X'
			|| str[1] == '%'));
}

t_arg_type	*fst_fmt_arg(const char *fmt)
{
	t_arg_type	*res;
	int			i;

	if (!fmt)
		return (NULL);
	i = -1;
	while (fmt[++i])
	{
		if (is_fmt_arg(fmt + i))
		{
			res = (t_arg_type *)malloc(sizeof(t_arg_type));
			if (!res)
				return (NULL);
			res->idx = i;
			res->type = fmt[i + 1];
			return (res);
		}
	}
	return (NULL);
}

int	fmt_arg_count(const char *str)
{
	int	i;
	int	cnt;

	if (!str)
		return (-1);
	i = -1;
	cnt = 0;
	while (str[++i])
	{
		if (is_fmt_arg(str + i))
			cnt++;
	}
	return (cnt);
}
