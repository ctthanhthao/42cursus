/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarcz <amarcz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 17:41:19 by amarcz            #+#    #+#             */
/*   Updated: 2024/10/29 15:48:19 by amarcz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

/*  FLAGS             */

typedef struct s_flags
{
	int	spec;
	int	width;
	int	left;
	int	zero;
	int	star;
	int	precision;
	int	hash;
	int	space;
	int	plus;
}	t_flags;

/*  PRINTF FUNCTIONS */

int		ft_printchar(char c, t_flags flags);
int		ft_printstring(char *str, t_flags flags);
int		ft_printdigits(int nr, t_flags flags);
int		ft_converthexa(unsigned long nr, int is_upper, t_flags flags);
int		ft_printpointer(void *ptr, t_flags flags);
int		ft_printunsigned(unsigned int nr, t_flags flags);
int		ft_printperc(t_flags flags);
int		ft_printf(const char *_format, ...);

/*  FLAG FUNCTIONS*/

int		ft_flag_precision(const char *str, int pos,
			va_list args, t_flags *flags);
t_flags	ft_flag_left(t_flags flags);
t_flags	ft_flags_digit(char c, t_flags flags);
t_flags	ft_flags_init(void);
t_flags	ft_flag_width(va_list args, t_flags flags);

/*  HELPER FUNCTION   */
size_t	ft_strlen(const char *str);
int		ft_ft_isdigit(int c);
int		ft_isflag(int c);
int		ft_istype(int c);
int		ft_is_formspec(int c);
int		ft_pad_width(int total_width, int size, int zero);
int		ft_printc(char c);
int		ft_left_allign(t_flags flags, int len);
int		ft_int_len(int nr);
int		ft_digit_format(int nr, t_flags flags, int len);

#endif  //PRINTF_H
