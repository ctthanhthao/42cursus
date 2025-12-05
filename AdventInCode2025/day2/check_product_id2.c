/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_product_id2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 14:12:45 by thchau            #+#    #+#             */
/*   Updated: 2025/12/03 09:06:59 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int main()
{
	int fd;
	char **product_ranges;
	char **range;
	int i = 0;
	unsigned long long	num1;
	unsigned long long	num2;
	unsigned long long tmp;
	unsigned long long result = 0;
	char *tmp_str;
	char *p;
	
    fd = open("test.txt", O_RDONLY);
    if (fd == -1) {
        perror("Error opening test.txt");
        return 1;
    }
	while ((p = get_next_line(fd)) != NULL)
	{
		product_ranges = ft_split(p, ',');
		if (product_ranges != NULL)
		{
			while (product_ranges[i])
			{
				range = ft_split(product_ranges[i], '-');
				if (range != NULL)
				{
					num1 = ft_atoll(range[0]);
					num2 = ft_atoll(range[1]);
					tmp = num1;
					while (tmp <= num2)
					{
						tmp_str = ft_lltoa(tmp);
						int len = ft_strlen(tmp_str);
						int found = 0;
						if (len % 2 == 0)
						{
							char *s1 = ft_substr(tmp_str, 0, len / 2);
							char *s2 = ft_substr(tmp_str, len/2, len);
							if (ft_memcmp(s1, s2, len/2) == 0)
							{
								printf("Invalid product id is %s\n", tmp_str);
								result += tmp;
								found = 1;
							}
							else if ((len/2) % 2 != 0)
							{
								int step = 2;
								char *t1 = ft_substr(tmp_str, 0, step);
								while (step < len)
								{
									char *t2 = ft_substr(tmp_str, step, step + 2);
									if (ft_memcmp(t1, t2, 2) != 0)
									{
										free(t2);
										break;
									}
									step += 2;
									if (step == len)
									{
										printf("Invalid product id is %s\n", tmp_str);
										result += tmp;
										found = 1;
									}
									free(t2);
								}
								free(t1);
							}
							free(s1);
							free(s2);
						}
						else
						{
							int step = 1;
							char *t1 = ft_substr(tmp_str, 0, step);
							while (step < len)
							{
								char *t2 = ft_substr(tmp_str, step, step + 1);
								if (ft_memcmp(t1, t2, 1) != 0)
								{
									free(t2);
									break;
								}
								step += 1;
								if (step == len)
								{
									printf("Invalid product id is %s\n", tmp_str);
									result += tmp;
									found = 1;
								}
								free(t2);
							}
							free(t1);
							
						}
						if (found == 0 && len % 3 == 0)
						{
							char *s1 = ft_substr(tmp_str, 0, 3);
							char *s2 = ft_substr(tmp_str, len/3, 3);
							char *s3 = ft_substr(tmp_str, len - len/3, 3);
							if ((ft_memcmp(s1, s2, len/3) == 0) 
								&& (ft_memcmp(s2, s3, len/3) == 0))
								{
									printf("Invalid product id is %s\n", tmp_str);
									result += tmp;
								}
							free(s1);
							free(s2);
							free(s3);
						}
						free(tmp_str);
						tmp++;
					}
				}
				free_split(range);
				i++;
			}
		}
		free_split(product_ranges);
		free(p);	
	}
	close(fd);
	printf("The result is %llu \n", result);
	return 0;
}