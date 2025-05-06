#include "get_next_line.h"
#include <stdlib.h>
#include <stdio.h>

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return (char *)(s);
		s++;
	}
	if (*s == '\0')
		return (char *)(s);
	return (NULL);
}

int main(void)
{
	const char	*str = "Hola Mundo";
	char	*result1 = ft_strchr(str, 'M');
	printf("Buscar 'M': %s\n", result1);
	char *result2 = ft_strchr(str, 'z');
	printf("Buscar 'z': %s\n", result2 ? result2 : "NULL");
	char *result3 = ft_strchr(str, '\0');
	if (result3)
		printf("Buscar '\\0': puntero válido (posición %ld)\n", result3 - str);
	else
		printf("Buscar '\\0': NULL\n");
	return 0;
}
