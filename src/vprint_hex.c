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

int	vprint_hex(va_list args);

int	vprint_hex_big(va_list args);

char	*ft_utoa(unsigned int u);

int	von_success(const int i, int (*f)(va_list), va_list args);

int	ft_ulog(const unsigned int base, const unsigned int n);
