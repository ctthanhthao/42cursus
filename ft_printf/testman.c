#include <stdio.h>
int	ft_printf(const char *str, ...);

int main()
{
	int r;
	int r1;
	r = ft_printf(" %p %p \n", 0, 0);
	r1 = printf(" %p %p \n", 0, 0);
	printf("ft %i - pt %i\n", r, r1);
	return (0);
}