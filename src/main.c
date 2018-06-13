#include "ft_printf.h"
#include <limits.h>

int	main(void)
{
	int a;

	a = 23;
//	ft_printf("%%\n");
	//printf("here: %%\n");
//	printf("test: %c\n", 'a');
//	ft_printf("%s\n", "hello");
//	ft_printf("%o\n", 100);
//	printf("CPU test: %p\n", &a);
//	ft_printf("%p\n", &a);
//	ft_printf("%b\n", 10);
//	printf("CPU test: %c\n", 'A');
//	ft_printf("%c\n", 'A');
//	printf("CPU test: %d\n", 12234);
//	ft_printf("%d\n", 12234);
//	ft_printf("%ld\n", 237469821234);
//	printf("CPU test: %ld\n", 237469821234);
//	ft_printf("%ld\n", 1234567812345678);
//	printf("%ld\n", 1234567812345678);
//	printf("%S\n", "");
//	printf("%s\n", "100% des gens qui parlent à Ly adorent Ly.");
//	ft_printf("%s\n", "100% des gens qui parlent à Ly adorent Ly.");
//	ft_printf("%S\n", L"갔갔갔갔갔갔갔갔갔갔갔갔갔갔갔갔갔갔갔갔");
//	printf("%C\n", L'A');
//	ft_printf("%C\n", L'A');
//	ft_printf("%04i\n", 42);
//	printf("%X\n", 10);
//	ft_printf("%X\n", 10);
//	printf("%D\n", 1273598);
//	ft_printf("%D\n", 1273598);
//	printf("%o\n", 0);
//	ft_printf("%p\n", 0);
//	printf("%10s\n", "cat");
//	ft_printf("%10s\n", "cat");
//	printf("CPU test: %x\n", 29);
//	ft_printf("%x\n", 29);
//	printf("% 4i\n", 42);
//	ft_printf("%04.5i", 42);
//	ft_printf("%04.2i", 42);
//	ft_printf("normal k =          [%kC ]\n", L'👼');
//	printf("%%o\n Lydie == |%o|\n", 'L'+'y'+'d'+'i'+'e');
//	ft_printf("%%o\n Lydie == |%o|\n", 'L'+'y'+'d'+'i'+'e');
//	ft_printf("%o\n", -0);
//	ft_printf("%o\n", 0);
// 	ft_printf("normal no k = [%S]\n", L"갔갔");
	ft_printf("%#o\n", INT_MAX);
	return (0);
}
