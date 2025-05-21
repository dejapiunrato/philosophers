#include <stddef.h>
#include <stddef.h>
#include <limits.h>

long	ft_atol(char *s)
{
	long long	num;
	int			neg;
	int			i;

	num = 0;
	neg = 1;
	i = 0;
	while (s[i] == ' ' || (s[i] >= '\t' && s[i] <= '\r'))
		i++;
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
			neg = -neg;
		i++;
	}
	while (s[i] >= '0' && s[i] <= '9')
	{
		num = num * 10 + (s[i] - '0');
		i++;
	}
	return ((long)(neg * num));
}
int main(void)
{
    char *test_cases[] = {
        "42",                          // Número positivo simple
        "-42",                         // Número negativo simple
        "   123",                      // Número con espacios iniciales
        "   -123",                     // Número negativo con espacios iniciales
        "0",                           // Cero
        "999999999999999999",          // Número fuera del rango de long positivo
        "-999999999999999999",         // Número fuera del rango de long negativo
        "2147483647",                  // Límite superior de int
        "-2147483648",                 // Límite inferior de int
        "9223372036854775807",         // Límite superior de long
        "-9223372036854775808",        // Límite inferior de long
        "++42",                        // Doble signo positivo
        "--42",                        // Doble signo negativo
        "+-42",                        // Signos mezclados
        "-+42",                        // Signos mezclados
        "abc123",                      // Letras antes de números
        "123abc",                      // Letras después de números
        "   +42abc",                   // Espacios, signo y letras después
        "",                            // Cadena vacía
        "   ",                         // Solo espacios
        "   +",                        // Espacios y signo sin número
        "   -",                        // Espacios y signo sin número
        NULL                           // Fin de los casos de prueba
    };

    printf("%-25s | %-20s | %-20s\n", "Input", "ft_atol", "atol");
    printf("--------------------------------------------------------------------------\n");

    for (int i = 0; test_cases[i] != NULL; i++) {
        char *input = test_cases[i];
        long ft_result = ft_atol(input);
        long std_result = atol(input);

        printf("%-25s | %-20ld | %-20ld\n", input, ft_result, std_result);
    }

    return 0;
}
