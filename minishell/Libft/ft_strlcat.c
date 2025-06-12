/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarcz <amarcz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 12:42:16 by amarcz            #+#    #+#             */
/*   Updated: 2024/09/26 17:40:47 by amarcz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_count(char *dest, char *src,
			unsigned int size, unsigned int dest_size)
{
	unsigned int	i;

	i = dest_size;
	while (*src && i < size - 1)
	{
		dest[i] = *src;
		i++;
		src++;
	}
	dest[i] = '\0';
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	dest_len;
	unsigned int	src_len;

	dest_len = 0;
	src_len = 0;
	if ((dest == NULL && size == 0))
		return (0);
	while (dest[dest_len] != '\0')
		dest_len++;
	while (src[src_len] != '\0')
		src_len++;
	if (size <= dest_len)
	{
		dest_len = size;
		return (dest_len + src_len);
	}
	if (size <= dest_len)
		return (size + src_len);
	ft_count(dest, src, size, dest_len);
	return (dest_len + src_len);
}
/*
#include <stdio.h>
int main()
{
    char des[] = "B6moIWAM9FzTwcsL";
    char src[] = "YUdo0KEjh7 XF4SmijRU 4QYT3B jF4";
    unsigned int nr = 0;
    unsigned int test;

    test = ft_strlcat(des, src, nr);
	//char b[0xF] = "nyan !";
	//test = ft_strlcat(((void*)0), b, 0);

    printf("result: %s\n", des);
    printf("number is: %d\n", test);
}
*/
/*
#include <string.h>
void	ft_print_result(int n)
{
	char c;

	if (n >= 10)
		ft_print_result(n / 10);
	c = n % 10 + '0';
	write (1, &c, 1);
}

int		main(void)
{
	char	*dest;
	int		arg;

	alarm(5);
	if (!(dest = (char *)malloc(sizeof(*dest) * 15)))
		return (0);
	memset(dest, 0, 15);
	memset(dest, 'r', 6);

	memset(dest, 'r', 15);
		ft_print_result(ft_strlcat(dest, "lorem ipsum dolor sit amet", 5));
		write(1, "\n", 1);
		write(1, dest, 15);

    return (0);
}
*/
