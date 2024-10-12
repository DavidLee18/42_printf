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

typedef struct s_arg_type
{
	int		idx;
	char	type;
}	t_arg_type;

int			fmt_arg_count(const char *str);

int			ft_printf(const char *fmt, ...);

int			ft_vprintf(const char *fmt, va_list args);

t_arg_type	*fst_fmt_arg(const char *fmt);

int			is_fmt_arg(const char *cs);

#endif
