// gcc -Wall -Wextra -Werror -I../include main_satol.c ../libft.a -o test_ft_satol

#include <stdio.h>
#include <limits.h>
#include "libft.h"  // Aquí debería estar tu typedef t_atol y los códigos de error

// Para mostrar el error en texto
const char *satol_error_to_str(int error)
{
	if (error == SATOL_SUCCESS)
		return "SATOL_SUCCESS";
	if (error == SATOL_OVERFLOW)
		return "SATOL_OVERFLOW";
	if (error == SATOL_INVALID_CHAR)
		return "SATOL_INVALID_CHAR";
	if (error == SATOL_NO_DIGITS)
		return "SATOL_NO_DIGITS";
	if (error == SATOL_EMPTY_STRING)
		return "SATOL_EMPTY_STRING";
	return "UNKNOWN_ERROR";
}

void	test_case(const char *str)
{
	t_satol	result = ft_satol(str);

	printf("Input: \"%s\"\n", str);
	printf("  -> value: %ld\n", result.value);
	printf("  -> error: %s\n\n", satol_error_to_str(result.error));
}

int main(void)
{
	printf("===== TEST ft_satol_strict =====\n\n");

	// Casos básicos
	test_case("42");
	test_case("-42");
	test_case("+42");
	test_case("   123");
	test_case("   -123");

	// Casos de overflow
	char long_max_str[32];
	char long_min_str[32];
	sprintf(long_max_str, "%ld", LONG_MAX);
	sprintf(long_min_str, "%ld", LONG_MIN);
	test_case(long_max_str);
	test_case(long_min_str);

	// Overflow explícito
	test_case("9223372036854775808");  // LONG_MAX + 1 en 64-bit
	test_case("-9223372036854775809"); // LONG_MIN - 1 en 64-bit

	// Casos con caracteres inválidos
	test_case("123abc");
	test_case("abc123");
	test_case("   +abc");

	// Casos con string vacío o sin dígitos
	test_case("");
	test_case("   ");
	test_case("   +  ");

	return (0);
}

