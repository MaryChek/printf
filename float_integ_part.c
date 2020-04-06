#include "ft_printf.h"

int     print_integ_part(int *exp, __uint128_t bits, const int *sign, t_type *type)
{
    t_long_num      p;
    __uint128_t     a;
    int             i;

    a = 51;
    init_array(&p);
    i = 0;
    if (*exp >= 0)
    {
        p.num[0] = 1;
        while (i++ < (*exp))
        {
            mul_long_num(&p, 0, 2, 0);
            if (((bits >> a) & 1) && i < 53)
                p.num[0] += 1;
            a--;
        }
    }
    else
        *exp = 0;
    print_array(p, *sign, type);
    
    return (a);
}

void    print_fract_part(int bit, int *exp, __uint128_t bits, t_type *type)
{
    t_long_num      p;
    LL_int         i;

    i = 5;
    int j = 0;
    init_array(&p);
    while ((*exp)++ < 53)
    {
        j++;
        mul_long_num(&p, 0, 10, 0);
        if (((bits >> bit) & 1))
            sum_long_num(&p, 0, i);
        bit--;
        i *= 5;
    }
    print_array(p, 0, type);
    i = 63;
    while (i >= 0)
    {
        if ((bits >> i) & 1)
            printf("1");
        else
            printf("0");
        i--;
        if (i == 62 || i == 51 || i == 38)
            printf(" ");
    }
}