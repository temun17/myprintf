#include "ft_printf.h"

int	main(void)
{
	int a;

	a = 23;
//	ft_printf("%%\n");
	//printf("here: %%\n");
//	printf("test: %c\n", 'a');
	ft_printf("%s\n", "hello");
	ft_printf("%o\n", 100);
//	printf("CPU test: %p\n", &a);
	ft_printf("%p\n", &a);
	ft_printf("%b\n", 10);
	printf("CPU test: %c\n", 'A');
	ft_printf("%c\n", 'A');
	printf("CPU test: %d\n", 12234);
	ft_printf("%d\n", 12234);
	return (0);
}
