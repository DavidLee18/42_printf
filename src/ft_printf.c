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
	va_list		args;
	int			acnt;
	t_arg_type	*arg_types;
	int			i;
	int			j;

	acnt = fmt_arg_count(fmt) + 1;
	if (acnt == 0)
		return (-1);
	else if (acnt == 1)
		return ((int)write(STDOUT_FILENO, fmt, ft_strlen(fmt)));
	arg_types = fmt_args(fmt, acnt - 1);
	va_start(args, acnt - 1);
	i = 0;
	j = 0;
	va_end(args);
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
		if (str[i] == '%' && (str[i + 1] == 'c' || str[i + 1] == 's'
				|| str[i + 1] == 'p' || str[i + 1] == 'd' || str[i + 1] == 'i'
				|| str[i + 1] == 'u' || str[i + 1] == 'x' || str[i + 1] == 'X'
				|| str[i + 1] == '%'))
			cnt++;
	}
	return (cnt);
}
