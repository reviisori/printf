/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: altikka <altikka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 14:08:42 by altikka           #+#    #+#             */
/*   Updated: 2022/04/29 17:49:23 by altikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include "vec.h"

typedef struct s_stat
{
	va_list			ap;
	long			value;
	int				sign;
	unsigned int	is_signed;	// : 1 [on/off]
	unsigned int	flags;		// : 5 [#-+ 0]
	unsigned int	width;
	unsigned int	preci;
	unsigned int	preci_on;	// : 1 [on/off]
	unsigned int	lenght;		// : 3 [hh,h,l,ll] [l,L]
	char			type;
	char			pad;
}			t_stat;

/*

int		tc_char(t_vec *dest, t_stat attr);
int		tc_dbl(t_vec *dest, t_stat attr);
int		tc_num(t_vec *dest, t_stat attr);
int		tc_ptr(t_vec *dest, t_stat attr);
int		tc_str(t_vec *dest, t_stat attr);

typedef int	(*t_STRUCT)(TYPE *, TYPE *);

static const t_STRUCT	g_NAME[9] = {
	tc_char,	//c
	tc_num,		//d
	tc_dbl,		//f
	tc_num,		//i
	tc_num,		//o
	tc_ptr,		//p
	tc_str,		//s
	tc_num,		//u
	tc_num		//xX
};

*/

int		ft_printf(const char *format, ...);
int		print_shop(char **str, const char *format, va_list ap);
int		press(t_vec *dest, const char *format, t_stat attr);
void	init_stats(t_stat *attr, va_list ap);
void	reset_stats(t_stat *attr);

#endif
