/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 11:53:42 by thchau            #+#    #+#             */
/*   Updated: 2024/11/28 16:24:04 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static	int	ft_alloc_words(char const *s, char c)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	while (*s)
	{
		if (*s != c && in_word == 0)
		{
			count ++;
			in_word = 1;
		}
		else if (*s == c)
			in_word = 0;
		s++;
	}
	return (count);
}

static char	*ft_worddup(char const *s, char c)
{
	char	*word;
	int		i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	word = (char *)malloc((i + 1) * sizeof(char));
	if (word == NULL)
		return (NULL);
	ft_strlcpy(word, s, i + 1);
	return (word);
}

static void	ft_free(char **s, int count)
{
	int	i;

	i = 0;
	while (i > count)
	{
		free(s[i]);
		i++;
	}
	free(s);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		w_len;
	int		idx_r;
	int		word_count;

	word_count = ft_alloc_words(s, c);
	result = (char **)malloc((word_count + 1) * sizeof(char *));
	if (result == NULL)
		return (NULL);
	w_len = 0;
	idx_r = 0;
	while (s[w_len] && word_count > 0)
	{
		while (s[w_len] == c)
			w_len++;
		if (!s[w_len])
			break ;
		result[idx_r] = ft_worddup(s + w_len, c);
		if (result[idx_r] == NULL)
			ft_free(result, idx_r);
		w_len += ft_strlen(result[idx_r++]);
	}
	result[idx_r] = NULL;
	return (result);
}
/*#include <stdio.h>
#include "ft_strlcpy.c"
#include "ft_strlen.c"
#include "ft_memcpy.c"
void	ft_print_result(char const *s)
{
	int		len;

	len = 0;
	while (s[len])
		len++;
	write(1, s, len);
}

int main()
{
	char s[]= "";
	char c = 'o';
	char **result = ft_split(s, c);
	if (result == NULL)
	{
		printf("Result is NULL\n");
		return 0;
	}
	for (int i =0; result[i]; i++)
	{
		printf("The word is %s\n", result[i]);
		free(result[i]);
	}
	printf("The s is %s\n", s);
	free(result);
	int i = 0;
	char **result;
	if (!(result = ft_split("   lorem   ipsum dolor     sit amet, 
	consectetur   adipiscing elit. Sed non risus. Suspendisse   ", ' ')))
			ft_print_result("NULL");
		else
		{
			while (result[i] != NULL)
			{
				ft_print_result(result[i]);
				write(1, "\n", 1);
				i++;
			}
		}
	return 0;
}*/