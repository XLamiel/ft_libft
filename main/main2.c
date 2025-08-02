#include <stdio.h>
#include <ctype.h>
#include <libft.h>  // Esto se resuelve gracias al -I
int main(void)
{
    printf("%d\n", isdigit('a'));
    ft_printf("%d\n", ft_isdigit('a'));
        printf("%d\n", isdigit('0'));
    ft_printf("%d\n", ft_isdigit('0'));
    return (0);
}
