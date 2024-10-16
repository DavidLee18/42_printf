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

int	vprint_hex(va_list args)
{
	unsigned int	u;
	char			*str;
	int				res;

	u = va_arg(args, unsigned int);
	str = ft_utox(u);
	if (!str)
		return (-1);
	res = (int)write(STDOUT_FILENO, str, ft_strlen(str));
	free(str);
	return (res);
}

int	vprint_hex_(va_list args)
{
	unsigned int	u;
	char			*str;
	int				res;

	u = va_arg(args, unsigned int);
	str = ft_utox_(u);
	if (!str)
		return (-1);
	res = (int)write(STDOUT_FILENO, str, ft_strlen(str));
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

int	von_success(const int i, int (*f)(va_list), va_list args)
{
	if (i < 0)
		return (i);
	return (i + (*f)(args));
}

int	ft_ulog(const size_t base, const size_t n)
{
	if (base == 0 || base == 1 || n == 0)
		return (-1);
	else if (n < base)
		return (0);
	return (1 + ft_ulog(base, n / base));
}
