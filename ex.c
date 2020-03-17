#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <limits.h>


int     main() {
    __uint128_t bit;
    double c = 10.0;
    bit = *(__uint128_t *)(&c);
    int exp = ((bit >> 52) & 0x7ff) - 1023;
    printf("exp = %d\n", exp);
    int sign;
    sign = bit >> 63;
    if (sign == 0)
        printf("sign = +\n");
    else
        printf("sign = -\n");
    int a = 51;
    printf("integ part = 1");
    while (exp-- > 0)
    {
        if ((bit >> a) & 1)
            printf("1");
        else
            printf("0");
        a--;
    }
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