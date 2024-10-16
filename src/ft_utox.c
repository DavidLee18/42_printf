/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utox.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehylee <jaehylee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 10:40:00 by jaehylee          #+#    #+#             */
/*   Updated: 2024/10/13 10:40:00 by jaehylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_utox(unsigned int u)
{
	char			*str;
	int				dgt_len;
	unsigned int	n;

	n = u;
	dgt_len = ft_ulog(16, u);
	if (dgt_len == -1)
		dgt_len = 0;
	str = (char *)ft_calloc(dgt_len + 2, sizeof(char));
	if (!str)
		return (NULL);
	str[dgt_len + 1] = 0;
	while (dgt_len >= 0)
	{
		str[dgt_len--] = "0123456789abcdef"[n % 16];
		n /= 16;
	}
	return (str);
}

char	*ft_utox_(unsigned int u)
{
	char			*str;
	int				dgt_len;
	unsigned int	n;

	n = u;
	dgt_len = ft_ulog(16, u);
	if (dgt_len == -1)
		dgt_len = 0;
	str = (char *)ft_calloc(dgt_len + 2, sizeof(char));
	if (!str)
		return (NULL);
	str[dgt_len + 1] = 0;
	while (dgt_len >= 0)
	{
		str[dgt_len--] = "0123456789ABCDEF"[n % 16];
		n /= 16;
	}
	return (str);
}

int	free_and_return(t_fmt_arg *arg, const int i)
{
	free_fmt_arg(arg);
	return (i);
}

size_t	ft_atoul(const char *str)
{
	int		l;
	size_t	res;

	l = ft_strlen(str);
	res = 0;
	while (--l >= 0)
		res = res * 10 + (str[l] - '0');
	return (res);
}

long	ft_atol(const char *str)
{
	int		l;
	long	sign;
	long	res;

	sign = (*str != '-') * 2 - 1;
	l = ft_strlen(str);
	res = 0;
	while (--l >= (sign == -1))
		res = res * 10 + sign * (str[l] - '0');
	return (res);
}
