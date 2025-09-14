// gcc -Wall -Wextra -Werror -I../include main_satoi.c ../libft.a -o test_ft_satoi

#include <stdio.h>
#include "libft.h"

// Prototipo de tu función
t_satoi ft_satoi(const char *str);

// Función auxiliar para imprimir resultados de manera legible
void print_result(const char *test_name, const char *str, t_satoi result)
{
    printf("Test: %-20s | Input: \"%s\"\n", test_name, str);
    printf("  Value: %-12d | Error: ", result.value);
    
    switch (result.error)
    {
        case SATOI_SUCCESS:      printf("SUCCESS"); break;
        case SATOI_OVERFLOW:     printf("OVERFLOW"); break;
        case SATOI_INVALID_CHAR: printf("INVALID_CHAR"); break;
        case SATOI_NO_DIGITS:    printf("NO_DIGITS"); break;
        case SATOI_EMPTY_STRING: printf("EMPTY_STRING"); break;
        default:                 printf("UNKNOWN(%d)", result.error);
    }
    printf("\n");
    printf("  ----------------------------------\n");
}

int main(void)
{
    printf("=== TESTING FT_SATOI ===\n\n");
    
    // Casos básicos
    print_result("Positive number", "42", ft_satoi("42"));
    print_result("Negative number", "-42", ft_satoi("-42"));
    print_result("With plus sign", "+123", ft_satoi("+123"));
    
    // Casos con espacios
    print_result("Leading spaces", "   456", ft_satoi("   456"));
    print_result("Trailing spaces", "789   ", ft_satoi("789   "));
    print_result("Mixed spaces", "  -123  ", ft_satoi("  -123  "));
    
    // Casos límite
    print_result("INT_MAX", "2147483647", ft_satoi("2147483647"));
    print_result("INT_MIN", "-2147483648", ft_satoi("-2147483648"));
    
    // Overflow casos
    print_result("Overflow positive", "2147483648", ft_satoi("2147483648"));
    print_result("Overflow negative", "-2147483649", ft_satoi("-2147483649"));
    print_result("Big overflow", "9999999999", ft_satoi("9999999999"));
    
    // Casos de error
    print_result("Empty string", "", ft_satoi(""));
    print_result("NULL pointer", "NULL", ft_satoi(NULL));
    print_result("Only spaces", "   ", ft_satoi("   "));
    print_result("Only sign +", "+", ft_satoi("+"));
    print_result("Only sign -", "-", ft_satoi("-"));
    
    // Caracteres inválidos
    print_result("Invalid start", "abc123", ft_satoi("abc123"));
    print_result("Invalid middle", "123abc456", ft_satoi("123abc456"));
    print_result("Invalid end", "123abc", ft_satoi("123abc"));
    print_result("Mixed invalid", "+123abc456", ft_satoi("+123abc456"));
    
    // Casos mixtos
    print_result("Zero", "0", ft_satoi("0"));
    print_result("Negative zero", "-0", ft_satoi("-0"));
    print_result("Multiple zeros", "000123", ft_satoi("000123"));
    
    // Casos edge
    print_result("Max digits", "2147483647", ft_satoi("2147483647"));
    print_result("Min digits", "-2147483648", ft_satoi("-2147483648"));
    
    printf("\n=== TEST COMPLETED ===\n");
    
    return 0;
}
