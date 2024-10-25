/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vprint_fmt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehylee <jaehylee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 06:09:13 by jaehylee          #+#    #+#             */
/*   Updated: 2024/10/13 06:09:13 by jaehylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	vprint_fmt(t_fmt_arg *farg, va_list args)
{
	if (farg->conv_spec == 'c')
		return (vprint_chr(farg, args));
	else if (farg->conv_spec == 's')
		return (vprint_str(farg, args));
	else if (farg->conv_spec == 'x' || farg->conv_spec == 'X')
		return (vprint_hex(farg, args));
	else if (farg->conv_spec == 'i' || farg->conv_spec == 'd')
		return (vprint_int(farg, args));
	else if (farg->conv_spec == 'u')
		return (vprint_uint(farg, args));
	else if (farg->conv_spec == '%')
		return (print_per(farg));
	else if (farg->conv_spec == 'p')
		return (printp(farg, args));
	else
		return (-1);
}

int	vprint_chr(const t_fmt_arg *farg, va_list args)
{
	unsigned char	c;
	int				i;
	int				j;

	c = va_arg(args, unsigned char);
	j = 0;
	if (farg->flags && farg->min_width && *(farg->min_width) > 1)
	{
		i = -1;
		if (farg->flags->adjust_left)
			j = (int)write(STDOUT_FILENO, &c, 1);
		while (++i < *(farg->min_width) && j >= 0)
			j = (int)write(STDOUT_FILENO, " ", 1);
		if (!farg->flags->adjust_left)
			j = (int)write(STDOUT_FILENO, &c, 1);
		return (j);
	}
	return ((int)write(STDOUT_FILENO, &c, 1));
}

int	vprint_str(const t_fmt_arg *farg, va_list args)
{
	char	*str;
	char	*temp;
	int		i;

	str = NULL;
	str = va_arg(args, char *);
	if (!str)
		return (-1);
	if (farg->prec && *(farg->prec) < ft_strlen(str))
		temp = ft_substr(str, 0, *(farg->prec));
	else
		temp = ft_strdup(str);
	i = sprint_f(farg, temp);
	free(temp);
	return (i);
}

int	vprint_int(const t_fmt_arg *farg, va_list args)
{
	int		x;
	char	*str;
	int		res;

	x = va_arg(args, int);
	str = ft_itoa(x);
	if (!str)
		return (-1);
	res = iprintf(farg, str);
	free(str);
	return (res);
}

int	vprint_uint(const t_fmt_arg *farg, va_list args)
{
	unsigned int	x;
	char			*str;
	int				res;

	x = va_arg(args, unsigned int);
	str = ft_utoa(x);
	if (!str)
		return (-1);
	res = uprintf(farg, str);
	free(str);
	return (res);
}
