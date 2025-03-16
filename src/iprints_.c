/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iprints_.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehylee <jaehylee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 11:33:18 by jaehylee          #+#    #+#             */
/*   Updated: 2024/10/18 11:33:18 by jaehylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	iprints_(const t_fmt_arg *farg, const char *num)
{
	if (farg->flags && farg->flags->sign && ft_isdigit(*num))
		return ((int)write(STDOUT_FILENO, "+", 1));
	else if (*num == '-')
		return ((int)write(STDOUT_FILENO, "-", 1));
	else if (farg->flags && farg->flags->blank)
		return ((int)write(STDOUT_FILENO, " ", 1));
	else
		return (0);
}

int	iprint_padz(const size_t len)
{
	int	i;
	int	j;

	j = 0;
	i = -1;
	while (j >= 0 && (size_t)++i < len)
		j += (int)write(STDOUT_FILENO, "0", 1);
	return (j);
}

size_t	idigit_len(const char *num)
{
	if (!num)
		return (0);
	else if (*num == '-')
		return (ft_strlen(num + 1));
	else if (ft_isdigit(*num))
		return (ft_strlen(num));
	else
		return (0);
}

_Bool	isignof(const char *num)
{
	return (num && *num == '-' && ft_isdigit(*(num + 1)));
}

int	iprintf2(const t_fmt_arg *farg, const char *num)
{
	int		j;
	size_t	l;

	j = 0;
	if (farg->prec && farg->flags)
	{
		l = usize_max(ft_strlen(num) - (*num == '0'),
				*(farg->prec) + isignof(num));
		if (!farg->flags->adjust_left && farg->min_width
			&& *(farg->min_width) > l)
			j += uprint_pad(*(farg->min_width) - l);
		j += iprints_(farg, num);
		if (*(farg->prec) > idigit_len(num))
			j += iprint_padz(*(farg->prec) - idigit_len(num));
		if (*(farg->prec) || *num != '0')
			j += iprint_digits(num);
		if (farg->flags->adjust_left && farg->min_width
			&& *(farg->min_width) > l)
			j += uprint_pad(*(farg->min_width) - l);
		return (j);
	}
	else
		return (iprintf3(farg, num));
}
