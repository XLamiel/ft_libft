// gcc -Wall -Wextra -Werror -I./include main.c libft.a -o test_ftprintf


#include <stdio.h>
#include "./include/libft.h"

int main(void)
{
    int ret_std, ret_ft;
    char c = 'A';
    char *str = "Hola 42";
    void *ptr = str;
    int num = -42;
    unsigned int unum = 424242;
    int hex = 255;

    printf("===== TEST ft_printf vs printf =====\n\n");

    // 2.1 %c
    printf("---- Test %%c ----\n");
    ret_std = printf("printf:    [%c]\n", c);
    ret_ft  = ft_printf("ft_printf: [%c]\n", c);
    printf("Return std: %d | ft: %d\n\n", ret_std, ret_ft);

    // 2.2 %s
    printf("---- Test %%s ----\n");
    ret_std = printf("printf:    [%s]\n", str);
    ret_ft  = ft_printf("ft_printf: [%s]\n", str);
    printf("Return std: %d | ft: %d\n\n", ret_std, ret_ft);

    // 2.3 %p
    printf("---- Test %%p ----\n");
    ret_std = printf("printf:    [%p]\n", ptr);
    ret_ft  = ft_printf("ft_printf: [%p]\n", ptr);
    printf("Return std: %d | ft: %d\n\n", ret_std, ret_ft);

    // NULL pointer
    ret_std = printf("printf NULL:    [%p]\n", NULL);
    ret_ft  = ft_printf("ft_printf NULL: [%p]\n", NULL);
    printf("Return std: %d | ft: %d\n\n", ret_std, ret_ft);

    // 2.4 %d
    printf("---- Test %%d ----\n");
    ret_std = printf("printf:    [%d]\n", num);
    ret_ft  = ft_printf("ft_printf: [%d]\n", num);
    printf("Return std: %d | ft: %d\n\n", ret_std, ret_ft);

    // 2.5 %i
    printf("---- Test %%i ----\n");
    ret_std = printf("printf:    [%i]\n", num);
    ret_ft  = ft_printf("ft_printf: [%i]\n", num);
    printf("Return std: %d | ft: %d\n\n", ret_std, ret_ft);

    // 2.6 %u
    printf("---- Test %%u ----\n");
    ret_std = printf("printf:    [%u]\n", unum);
    ret_ft  = ft_printf("ft_printf: [%u]\n", unum);
    printf("Return std: %d | ft: %d\n\n", ret_std, ret_ft);

    // 2.7 %x
    printf("---- Test %%x ----\n");
    ret_std = printf("printf:    [%x]\n", hex);
    ret_ft  = ft_printf("ft_printf: [%x]\n", hex);
    printf("Return std: %d | ft: %d\n\n", ret_std, ret_ft);

    // 2.8 %X
    printf("---- Test %%X ----\n");
    ret_std = printf("printf:    [%X]\n", hex);
    ret_ft  = ft_printf("ft_printf: [%X]\n", hex);
    printf("Return std: %d | ft: %d\n\n", ret_std, ret_ft);

    // 2.9 %%
    printf("---- Test %%%% ----\n");
    ret_std = printf("printf:    [%%]\n");
    ret_ft  = ft_printf("ft_printf: [%%]\n");
    printf("Return std: %d | ft: %d\n\n", ret_std, ret_ft);

    // 3.0 %
    printf("---- Test %% ----\n");
    //ret_std = printf("printf:    [%]\n");
    ret_ft  = ft_printf("ft_printf: [%]\n");
    printf("Return std: no | ft: %d\n\n", ret_ft);

    return (0);
}
