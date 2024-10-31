//#include "include/ft_printf.h"
#include "ft_printf.c"
#include <stdio.h>
#include <limits.h>

int main ()
{
	char c = '0' + 256;
	int r = 0;
	int r1;

/*	// c
	printf("===================================\n");
	r = ft_printf("ft char |%02c|\n", '0' + 256);
	r1 = printf("pt char |%02c|\n", '0' + 256);
	printf("ft_printf %i - printf %i\n", r, r1);
	// c with flags
	printf("===================================\n");
	r = ft_printf("ft char % *c\n", 10, c);
	r1 = printf("pt char % *c\n", 10, c);
	printf("ft_printf %i - printf %i\n", r, r1);
	// s
	printf("===================================\n");
	char *s = "Hello World";
	r = ft_printf("ft  s |%0*.5s| \n", 20, s);
	r1 = printf("pt  s |%0*.5s| \n", 20, s);
	printf("ft_printf %i - printf %i\n", r, r1);
	s = NULL;
	r = ft_printf("ft  NULL %s NULL \n", s);
	r1 = printf("pt  NULL %s NULL \n", s);
	printf("ft_printf %i - printf %i\n", r, r1);
	// d
	printf("===================================\n");
	r = ft_printf("ft decimal  %d %d %d %d %d %.d %d\n", INT_MAX, INT_MIN, LONG_MAX, 
LONG_MIN, ULONG_MAX, 0, -42);
	r1 = printf("pt decimal  %d %d %d %d %d %.d %d\n", INT_MAX, INT_MIN, LONG_MAX, 
LONG_MIN, ULONG_MAX, 0, -42);
	printf("ft_printf %i - printf %i\n", r, r1);
	r = ft_printf("ft decimal |%+010d| |%015.5d| |%#+7.6d|\n", 45, (int)-2147483648, 21474);
	r1 = printf("pt decimal |%+010d| |%015.5d| |%#+7.6d|\n", 45, (int)-2147483648, 21474);
	printf("ft_printf %i - printf %i\n", r, r1);
	// i
	printf("===================================\n");
	r = ft_printf("|%5p|\n", (void *)0);
	r1 = printf("|%5p|\n", (void *)0);
	printf("ft_printf %i - printf %i\n", r, r1);
*/	
	// char *buffer;
    // size_t size;
    
    // // Open a memory stream to capture output
    // FILE *memstream = open_memstream(&buffer, &size);
    // if (!memstream) {
    //     perror("open_memstream failed");
    //     return 1;
    // }

    // // Save original stdout and redirect to memory stream
    // FILE *old_stdout = stdout;
    // stdout = memstream;

 //   ft_printf("ft |%.d|, %.d, %.d, %.d, %.d, %.d, %.d, %.d", 0, 5, -1, -10, 100, -1862, INT_MIN, INT_MAX);
	//printf("pt %.d, %.d, %.d, %.d, %.d, %.d, %.d, %.d", 0, 5, -1, -10, 100, -1862, INT_MIN, INT_MAX);
    // Restore stdout
    // fflush(stdout);
    // stdout = old_stdout;
    // fclose(memstream);

    // printf("Captured output: %s", buffer);  // Print the captured output
    //free(buffer);  // Free the memory allocated by open_memstream
/*	r = ft_printf("%01.x, %01.x, %01.x, %01.x, %01.x, %01.x, %01.x, %01.x, %01.x, %01.x\n", 0, 5, -1, -10, 0x1234, -1862, 0xABCDE, INT_MIN, INT_MAX, 
UINT_MAX);
	r1 = printf("%01.x, %01.x, %01.x, %01.x, %01.x, %01.x, %01.x, %01.x, %01.x, %01.x\n", 0, 5, -1, -10, 0x1234, -1862, 0xABCDE, INT_MIN, INT_MAX, 
UINT_MAX);
	printf("ft_printf %i - printf %i\n", r, r1);
	r = ft_printf("%5p, %5p, %5p, %5p, %5p, %5p\n", (void *)0, (void *)0xABCDE,
	 (void *)ULONG_MAX, (void *)LONG_MIN, (void *)-1, (void *)-2352);
	r1 = printf("%5p, %5p, %5p, %5p, %5p, %5p\n", (void *)0, (void *)0xABCDE,
	  (void *)ULONG_MAX, (void *)LONG_MIN, (void *)-1, (void *)-2352);
	printf("ft_printf %i - printf %i\n", r, r1);
	// u
	printf("===================================\n");
	r = ft_printf("ft u %u \n", 0);
	r1 = printf("pt u %u \n", 0);
	printf("ft_printf %i - printf %i\n", r, r1);
	printf("===================================\n");
	r = ft_printf("ft u %u %u %u %u %u\n", INT_MAX, INT_MIN, LONG_MAX, 0, -42);
	r1 = printf("pt u %u %u %u %u %u\n", INT_MAX, INT_MIN, LONG_MAX, 0, -42);
	printf("ft_printf %i - printf %i\n", r, r1);	
*//*	// p
	printf("===================================\n");
	int value = 12345;
	int *pt = &value;
	r = ft_printf("ft pointer |%-13p| |%-14p| \n", ULONG_MAX, -ULONG_MAX);
	r1 = printf("pt pointer |%-13p| |%-14p| \n", ULONG_MAX, -ULONG_MAX);
	printf("ft_printf %i - printf %i\n", r, r1);
	r = ft_printf("ft pointer |%-153p%0110.8x%110p|\n" ,(void*)17240180584784891087lu,2705171059u,(void*)1312307382483808423lu);
	r1 = printf("pt pointer |%-153p%0110.8x%110p|\n" ,(void*)17240180584784891087lu,2705171059u,(void*)1312307382483808423lu);
	printf("ft_printf %i - printf %i\n", r, r1);
	r = ft_printf("ft NULL pointer %p\n", NULL);
	r1 = printf("pt NULL pointer %p\n", NULL);
	printf("ft_printf %i - printf %i\n", r, r1);
	// x
	printf("===================================\n");
	r = ft_printf("ft hex %-2x %-13x\n", -1, UINT_MAX);
	r1 = printf("pt hex %-2x %-13x\n", -1, UINT_MAX);
	printf("ft_printf %i - printf %i\n", r, r1);
	r = ft_printf("ft hex %#x %#x %#x %#x %#x %#x %#x\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	r1 = printf("pt hex %#x %#x %#x %#x %#x %#x %#x\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	printf("ft_printf %i - printf %i\n", r, r1);
*/	r = ft_printf("%#5.x\n", 5);
	r1 = printf("%#5.x\n", 5);
	printf("ft_printf %i - printf %i\n", r, r1);
/*	// X
	printf("===================================\n");
	r = ft_printf("ft HEX %#X %#X\n", 16, -100);
	r1 = printf("pt HEX %#X %#X\n", 16, -100);
	printf("ft_printf %i - printf %i\n", r, r1);
	r = ft_printf("ft HEX %#X %#X\n", 0, -1);
	r1 = printf("pt HEX %#X %#X\n", 0, -1);
	printf("ft_printf %i - printf %i\n", r, r1);
	// %
	printf("===================================\n");
	r = ft_printf("ft 100%%%c\n", c);
	r1 = printf("pt 100%%%c\n", c);
	printf("ft_printf %i - printf %i\n", r, r1);
	// NULL
	printf("===================================\n");
	r = ft_printf(NULL);
//	r1 = printf(NULL);
	printf("NULL ft_printf %i - printf %i\n", r, r1);
	// test random
	printf("================= random test ==================\n");
	r = ft_printf("ft \001\002\007\v\010\f\r\n");
	r1 = printf("pt \001\002\007\v\010\f\r\n");
	printf("ft_printf %i - printf %i\n", r, r1);
	
/*	int n = 0;
	int re = -(n % 10);
	int *p = &n;
	const char buff[16];
	printf("p is |%#%%d|\n", 2551);
//	printf("len is %i\n", ft_strlen(buff));
//	printf("|%010.4li|\n", 25566666666666);
//	printf("|%.5f|\n", 56.0);
//	printf("|%---.8s|\n", "Hi");
//	printf("% 5#d\n", 255);
//	printf("|%5d|\n", -42);
*/
	return (0);
}