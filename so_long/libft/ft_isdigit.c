/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 08:54:29 by thchau            #+#    #+#             */
/*   Updated: 2024/09/19 15:54:14 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

/*#include <stdio.h>
int	main(void)
{
	char *str = "";
	char *str1 = "0";
	char *str2 = "dfd23hgdhgu";
	char *str3 = "1234*^%%565";
	char *str4 = "23423432454";
	printf("if str is %s then return %d\n", str, ft_str_is_numeric(str));
	printf("if str is %s then return %d\n", str1, ft_str_is_numeric(str1));
	printf("if str is %s then return %d\n", str2, ft_str_is_numeric(str2));
	printf("if str is %s then return %d\n", str3, ft_str_is_numeric(str3));
	printf("if str is %s then return %d\n", str4, ft_str_is_numeric(str4));
	return (0);
}*/
