#include "../include/so_long.h"

void ft_error(int n)
{
    if(n == 22 || n == 52)
    {
        //ft_printf("%s: %s\n", local, strerror(n));
        ft_printf("Usage: ./so.long <filename>.ber\n");
        exit(n);
    }

    exit(n);
}
