/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phofer <phofer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 16:38:32 by phofer            #+#    #+#             */
/*   Updated: 2025/06/04 19:30:50 by phofer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

void	ft_putchar(char c);
void	ft_putnbr(int *count, int n);
void	print_x(int *count, unsigned int n, char c);
void	print_u(int *count, unsigned int n);
void	print_p_rec(unsigned long addr, int *count);
void	print_p(int *count, void *ptr);
void	print_num(int *count, int n);
void	print_str(int *count, const char *str);
void	print_c(int *count, int str);
int		print_function(int *count, int i, va_list args, const char *phumat);
int		ft_printf(const char *phumat, ...);

#endif
