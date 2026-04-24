/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phofer <phofer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 18:28:40 by phofer            #+#    #+#             */
/*   Updated: 2025/05/24 19:03:34 by phofer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	size_t	len;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (NULL);
	len = (ft_strlen(s1) + ft_strlen(s2));
	new = malloc(len + 1);
	if (!new)
		return (NULL);
	i = -1;
	while (s1[++i])
		new[i] = s1[i];
	j = 0;
	while (s2[j])
	{
		new[i] = s2[j];
		++i;
		++j;
	}
	new[i] = '\0';
	return (new);
}
/*
#include <stdio.h>
#include <string.h>

void print_result(const char *desc, char *result) {
    if (result)
        printf("%s: \"%s\"\n", desc, result);
    else
        printf("%s: NULL (allocation failed or invalid input)\n", desc);
    free(result);  // Safe even if result is NULL
}

int main(void) {
    // Normal cases
    print_result("Normal case", ft_strjoin("Hello, ", "World!"));
    print_result("Empty prefix", ft_strjoin("", "World!"));
    print_result("Empty suffix", ft_strjoin("Hello, ", ""));
    print_result("Both empty", ft_strjoin("", ""));

    // Special characters
    print_result("With newline", ft_strjoin("Line1\n", "Line2"));
    print_result("With null-like chars", ft_strjoin("abc\0def", "ghi"));

    // Edge cases: NULL inputs
    // These would cause undefined behavior unless ft_strjoin checks for NULL.
    // Uncommenting the following lines should be avoided 
	unless you've explicitly handled NULL inside ft_strjoin.
    print_result("s1 is NULL", ft_strjoin(NULL, "test"));
    print_result("s2 is NULL", ft_strjoin("test", NULL));
    print_result("Both are NULL", ft_strjoin(NULL, NULL));
    

    // Large input
    char *long1 = malloc(1000001);
    char *long2 = malloc(1000001);
    if (long1 && long2) {
        memset(long1, 'A', 1000000); long1[1000000] = '\0';
        memset(long2, 'B', 1000000); long2[1000000] = '\0';
       // print_result("Large input", ft_strjoin(long1, long2));
    } else {
        printf("Large input: Allocation for test strings failed.\n");
    }
//    free(long1);
//    free(long2);

	char *res = ft_strjoin(long1, long2);
	if (res) {
    	printf("Large input: Length = %zu\n", strlen(res));
    	free(res);
	} else {
    	printf("Large input: Failed to allocate\n");
	}
    return 0;
}
*/
