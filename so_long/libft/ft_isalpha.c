/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 08:52:43 by thchau            #+#    #+#             */
/*   Updated: 2024/09/19 15:54:04 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'));
}

/*#include <stdio.h>
int main(void)
{
	char *str = "";
	char *str1 = "dfdhgdhgu";
	char *str2 = "dfd23hgdhgu";
	char *str3 = "dfdhg&*^%%ghgu";
	char *str4 = "GAAHDHADdfdsdsd";
	printf("if str is %s then return %d\n", str, ft_str_is_alpha(str));
	printf("if str is %s then return %d\n", str1, ft_str_is_alpha(str1));
	printf("if str is %s then return %d\n", str2, ft_str_is_alpha(str2));
	printf("if str is %s then return %d\n", str3, ft_str_is_alpha(str3));
	printf("if str is %s then return %d\n", str4, ft_str_is_alpha(str4));
	return (0);
}*/
