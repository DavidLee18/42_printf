/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vprint_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehylee <jaehylee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 08:24:47 by jaehylee          #+#    #+#             */
/*   Updated: 2024/10/13 08:24:47 by jaehylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	vprint_hex(const t_fmt_arg *farg, va_list args)
{
	unsigned int	u;
	char			*str;
	int				res;

	u = va_arg(args, unsigned int);
	if (farg->conv_spec == 'x')
		str = ft_utox(u);
	else
		str = ft_utox_(u);
	if (!str)
		return (-1);
	res = xprintf(farg, str);
	free(str);
	return (res);
}

char	*ft_utoa(unsigned int u)
{
	char			*str;
	int				dgt_len;
	unsigned int	n;

	n = u;
	dgt_len = ft_ulog(10, u);
	if (dgt_len == -1)
		dgt_len = 0;
	str = (char *)ft_calloc(dgt_len + 2, sizeof(char));
	if (!str)
		return (NULL);
	str[dgt_len + 1] = 0;
	while (dgt_len >= 0)
	{
		str[dgt_len--] = '0' + (n % 10);
		n /= 10;
	}
	return (str);
}

int	ft_ulog(const size_t base, const size_t n)
{
	if (base == 0 || base == 1 || n == 0)
		return (-1);
	else if (n < base)
		return (0);
	return (1 + ft_ulog(base, n / base));
}

int	printp(t_fmt_arg *farg, va_list args)
{
	if (!(farg->flags))
		farg->flags = init_flags();
	if (!(farg->flags))
		return (-1);
	farg->flags->alt_form = 1;
	return (vprint_hex(farg, args));
}

int	iprintf(const t_fmt_arg *farg, const char *num)
{
	int	j;

	j = 0;
	if (farg->prec && farg->flags && (farg->flags->sign || farg->flags->blank))
	{
		if (!farg->flags->adjust_left
			&& farg->min_width && *(farg->min_width) > *(farg->prec) + 1)
			j = uprint_pad(*(farg->min_width) - *(farg->prec) - 1);
		j = iprints_(farg, j, num);
		if (j >= 0 && *(farg->prec) > idigit_len(num))
			j = iprint_padz(*(farg->prec) - idigit_len(num), num);
		if (farg->flags->adjust_left
			&& farg->min_width && *(farg->min_width) > *(farg->prec) + 1)
			j = uprint_pad(*(farg->min_width) - *(farg->prec) - 1);
		return (j);
	}
	else
		return (iprintf2(farg, num));
}
