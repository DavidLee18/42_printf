/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehylee <jaehylee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 03:41:54 by jaehylee          #+#    #+#             */
/*   Updated: 2024/10/12 03:41:54 by jaehylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "../libft/libft.h"

// typedef struct s_arg_type
// {
// 	int		idx;
// 	char	type;
// }	t_arg_type;

int			ft_printf(const char *fmt, ...);

int			ft_vprintf(const char *fmt, va_list args);

int			*fst_fmt_arg(const char *fmt);

int			is_fmt_arg(const char *cs);

int			print_fmt(const char t, va_list args);

int			sum_or_error(const	int i, const int j, const int k);

#endif
