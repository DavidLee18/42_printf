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

char	*gc_utox(t_list **dyn, unsigned int u)
{
	char			*str;
	int				dgt_len;
	unsigned int	n;

	n = u;
	dgt_len = ft_ulog(16, u);
	if (dgt_len == -1)
		dgt_len = 0;
	str = (char *)gc_calloc(dyn, dgt_len + 2, sizeof(char));
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

char	*gc_utox_(t_list **dyn, unsigned int u)
{
	char			*str;
	int				dgt_len;
	unsigned int	n;

	n = u;
	dgt_len = ft_ulog(16, u);
	if (dgt_len == -1)
		dgt_len = 0;
	str = (char *)gc_calloc(dyn, dgt_len + 2, sizeof(char));
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

size_t	ft_atoul(const char *str)
{
	size_t	l;
	size_t	res;
	size_t	i;

	l = ft_strlen(str);
	res = 0;
	i = 0;
	while (i < l)
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (res);
}

long	ft_atol(const char *str)
{
	int		l;
	long	sign;
	long	res;
	int		i;

	sign = (*str != '-') * 2 - 1;
	l = ft_strlen(str);
	res = 0;
	i = 0;
	while (i + (sign == -1) < l)
	{
		res = res * 10 + sign * (str[i] - '0');
		i++;
	}
	return (res);
}
