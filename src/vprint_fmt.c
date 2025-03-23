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

int	vprint_fmt(t_list **dyn, const int fd, t_fmt_arg *farg, va_list args)
{
	if (farg->conv_spec == 'c')
		return (vprint_chr(fd, farg, args));
	else if (farg->conv_spec == 's')
		return (vprint_str(dyn, fd, farg, args));
	else if (farg->conv_spec == 'x' || farg->conv_spec == 'X')
		return (vprint_hex(dyn, fd, farg, args));
	else if (farg->conv_spec == 'i' || farg->conv_spec == 'd')
		return (vprint_int(dyn, fd, farg, args));
	else if (farg->conv_spec == 'u')
		return (vprint_uint(dyn, fd, farg, args));
	else if (farg->conv_spec == '%')
		return (print_per(fd, farg));
	else if (farg->conv_spec == 'p')
		return (printp(dyn, fd, farg, args));
	else if (farg->conv_spec == 'v')
		return (print_vec(dyn, fd, farg, args));
	else
		return (-1);
}

int	vprint_chr(const int fd, const t_fmt_arg *farg, va_list args)
{
	unsigned char	c;
	size_t			i;
	int				j;

	c = va_arg(args, int);
	j = 0;
	if (farg->flags && farg->min_width && *(farg->min_width) > 1)
	{
		i = 0;
		if (farg->flags->adjust_left)
			j += (int)write(fd, &c, 1);
		while (i < *(farg->min_width) - 1)
		{
			j += (int)write(fd, " ", 1);
			i++;
		}
		if (!farg->flags->adjust_left)
			j += (int)write(fd, &c, 1);
		return (j);
	}
	return (cprintf(fd, farg, c));
}

int	vprint_str(t_list **dyn, const int fd, const t_fmt_arg *farg, va_list args)
{
	char	*str;
	char	*temp;
	int		i;

	str = NULL;
	str = va_arg(args, char *);
	if (!str && (!farg->prec || *(farg->prec) >= 6))
	{
		temp = gc_calloc(dyn, 7, sizeof(char));
		if (!temp)
			return (-1);
		ft_strlcpy(temp, "(null)", 7);
	}
	else if (!str || !*str)
		return (0);
	else if (farg->prec && *(farg->prec) < ft_strlen(str))
		temp = gc_substr(dyn, str, 0, *(farg->prec));
	else
		temp = gc_strdup(dyn, str);
	i = sprint_f(fd, farg, temp);
	return (i);
}

int	vprint_int(t_list **dyn, const int fd, const t_fmt_arg *farg, va_list args)
{
	int		x;
	char	*str;
	int		res;

	x = va_arg(args, int);
	str = gc_itoa(dyn, x);
	if (!str)
		return (-1);
	res = iprintf(fd, farg, str);
	return (res);
}

int	vprint_uint(t_list **dyn, const int fd, const t_fmt_arg *farg, va_list args)
{
	unsigned int	x;
	char			*str;
	int				res;

	x = va_arg(args, unsigned int);
	str = gc_utoa(dyn, x);
	if (!str)
		return (-1);
	res = uprintf(fd, farg, str);
	return (res);
}
