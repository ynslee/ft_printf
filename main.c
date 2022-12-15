#include <stdio.h>
#include "ft_printf.h"

int main()
{
	printf("%u \n", printf("Hello World!\n"));
	printf("%u \n", ft_printf("Hello World!\n"));
	printf("%u \n", printf("Hello World!\n"));
	printf("%u \n", ft_printf("Hello World!\n"));
	printf("%u \n", printf("Hello World!\n"));
	printf("%u \n", ft_printf("Hello World!\n"));
	return (0);
}
