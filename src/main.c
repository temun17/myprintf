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
	return (0);
}
