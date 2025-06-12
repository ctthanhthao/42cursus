/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarcz <amarcz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 12:41:52 by amarcz            #+#    #+#             */
/*   Updated: 2024/09/24 12:42:53 by amarcz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	if (!s)
		return ;
	ft_putstr_fd(s, fd);
	write (fd, "\n", 1);
}
/*
int main (void)
{
    char txt[] = "HelloWorld!";
    ft_putendl_fd(txt, 1);
    ft_putendl_fd(txt, 1);

    return (0);
}
*/
