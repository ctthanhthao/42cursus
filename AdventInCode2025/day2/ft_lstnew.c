/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 19:42:47 by thchau            #+#    #+#             */
/*   Updated: 2024/09/22 20:03:12 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*node;

	node = (t_list *)malloc(sizeof(t_list));
	if (node == NULL)
		return (NULL);
	node->content = content;
	node->next = NULL;
	return (node);
}
/*#include <stdio.h>
int main()
{
	char *s = "Hello World";
	t_list *node = ft_lstnew((char *)s);
	printf("content of node is %s\n", (char *)node->content);
	if (node->next == NULL)
	{
		printf("next of node is null\n");
		free(node);
		return 0;
	}
	return 1;
}*/