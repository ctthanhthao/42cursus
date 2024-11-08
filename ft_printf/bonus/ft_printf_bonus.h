/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 21:14:15 by thchau            #+#    #+#             */
/*   Updated: 2024/11/08 15:25:38 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include "../include/ft_printf.h"

typedef struct s_flags
{
	int	minus;
	int	space;
	int	plus;
	int	hash;
	int	precision;
	int	width;
	int	dot;
	int	zero;
}			t_flags;

int		ft_process(const char **str, va_list args);

int		ft_handledi(long num, t_flags *flags);
int		ft_handleu(long num, t_flags *flags);
int		handledi_zero_dot(char *num_str, unsigned int len,
			int sign, t_flags *flags);
int		handledi_minus_dot(char *num_str, int sign, t_flags *flags);
int		handledi_dot(char *num_str, unsigned int len, int sign, t_flags *flags);

int		ft_handlechar(char c, t_flags *flags);
int		ft_handlechars(char *arg, t_flags *flags);

int		ft_handleptr(unsigned long num, t_flags *flags);
int		ft_handlehex(unsigned long num, t_flags *flags, int is_upper);
int		handlehex_hash_dot(char *num_str, unsigned int len,
			t_flags *flags, char *zerox);
int		handlehex_zero_hash_dot(char *num_str, unsigned int len,
			t_flags *flags, char *zerox);
int		handlehex_minus_hash_dot(char *num_str, t_flags *flags, char *zerox);

int		handle_width(unsigned int width, unsigned int len, int zero);
int		handle_precision(char *s, int precision, int is_string,
			int leading_zero);

t_flags	*ft_parseflags(const char **str, va_list args);
void	*convert_num_to_hex(char *num_str, unsigned long num, int isUpper);

#endif // End of include guard