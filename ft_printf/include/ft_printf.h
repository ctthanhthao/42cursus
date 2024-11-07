/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 21:14:15 by thchau            #+#    #+#             */
/*   Updated: 2024/11/06 11:14:37 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int				ft_printf(const char *str, ...);
int				ft_process(const char **str, va_list args);
int				ft_printchar(char c);
int				ft_printchars(const char *str);
int				ft_printhex(unsigned long num, int isUpper);
int				ft_printu(unsigned int num);
int				ft_printptr(unsigned long num);
int				ft_printdi(int n);
int				ft_isdigit(int c);
int				ft_atoi(const char **ptr);
char			*ft_itoa(long n);
char			*ft_strdup(const char *src);

void			*ft_memset(void *s, int c, size_t n);
void			*ft_strreverse(char *num_str);
void			*ft_memcpy(void *dest, const void *src, size_t n);

unsigned int	ft_strlen(const char *s);
#endif // End of include guard