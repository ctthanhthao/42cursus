/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 09:27:09 by thchau            #+#    #+#             */
/*   Updated: 2025/02/16 12:37:28 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	s1len;
	size_t	s2len;

	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	str = malloc(sizeof(char) * (s1len + s2len + 1));
	if (!str)
		return (NULL);
	ft_memcpy(str, s1, s1len);
	ft_memcpy(str + s1len, s2, s2len + 1);
	str[s1len + s2len] = '\0';
	return (str);
}

/*#include <stdio.h>
#include "ft_strlen.c"
#include "ft_strlcpy.c"
#include "ft_memcpy.c"
int main()
{
	char *s1 = "111";
	char *s2 = "223";
	char *s3 = ft_strjoin(s1, s2);
	printf("s3 is %s\n", s3);
	return 0;
}
*/