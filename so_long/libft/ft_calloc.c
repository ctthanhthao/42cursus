/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 16:14:28 by thchau            #+#    #+#             */
/*   Updated: 2024/09/19 19:44:33 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	total_size;
	void	*ptr;

	total_size = count * size;
	ptr = malloc(total_size);
	if (ptr == NULL)
		return (NULL);
	ft_memset(ptr, 0, total_size);
	return (ptr);
}
/*#include <stdio.h>
int main() {
    int *arr;
    int n = 5;

	printf("sizeof(int) is %lu\n", sizeof(int));
    // Allocate memory for an array of 5 integers
    arr = (int *)ft_calloc(n, sizeof(int));
	printf("sizeof(arr) is %lu\n", sizeof(arr));

    // Check if memory allocation was successful
    if (arr == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    // The allocated memory is initialized to zero
    printf("Initial values after calloc:\n");
    for (int i = 0; i < n; i++) {
        printf("arr[%d] = %d\n", i, arr[i]);
    }

    // Assign values to the array
    for (int i = 0; i < n; i++) {
        arr[i] = i + 1;
    }

    printf("\nValues after assignment:\n");
    for (int i = 0; i < n; i++) {
        printf("arr[%d] = %d\n", i, arr[i]);
    }
    // Free the allocated memory
    free(arr);

    return 0;
}*/