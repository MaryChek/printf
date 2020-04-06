#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <limits.h>
# include "ft_printf.h"

int     main() 
{
    __uint128_t bit;
    double c = -127800000000000000000000000000000000000000000.0;
    //printf("%f\n", c);
    bit = *(__uint128_t *)(&c);
    int exp = ((bit >> 52) & 0x7ff) - 1023;
    //printf("exp = %d\n", exp);
    int sign;
    sign = (bit >> 63) & 1;
    /*if (sign == 0)
        printf("sign = +\n");
    else
        printf("sign = -\n");*/
    print_integ_part(&exp, bit, &sign);
    printf("\n");
    int i = 63;
    while (i >= 0)
    {
        if ((bit >> i) & 1)
            printf("1");
        else
            printf("0");
        i--;
        if (i == 62 || i == 51)
            printf(" ");
    }
    return 0;
}