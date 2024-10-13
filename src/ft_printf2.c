/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehylee <jaehylee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 06:09:13 by jaehylee          #+#    #+#             */
/*   Updated: 2024/10/13 06:09:13 by jaehylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	vprint_fmt(const char t, va_list args)
{
	if (t == 'c')
		return (vprint_chr(args));
	else if (t == 's')
		return (vprint_str(args));
	else if (t == 'p' || t == 'x')
		return (vprint_hex(args));
	else if (t == 'X')
		return (vprint_hex_big(args));
	else if (t == 'i')
		return (vprint_int(args));
	else if (t == 'u')
		return (vprint_uint(args));
	else if (t == 'd')
		return (vprint_dec(args));
	else if (t == '%')
		return ((int)write(STDOUT_FILENO, "%", 1));
}

int	vprint_chr(va_list args)
{
	unsigned char	c;

	c = va_arg(args, (unsigned char));
	return ((int)write(STDOUT_FILENO, &c, 1));
}

int	vprint_str(va_list args)
{
	char	*str;

	str = NULL;
	str = va_arg(args, (char *));
	if (!str)
		return (-1);
	return ((int)write(STDOUT_FILENO, str, ft_strlen(str)));
}

int	vprint_hex(va_list args);

int	vprint_hex_big(va_list args);
