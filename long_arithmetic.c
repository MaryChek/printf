#include "ft_printf.h"

void    init_array(t_long_num *p)
{
    int i;

    i = -1;
    while (++i < 100)
        p->num[i] = 0; 
    p->real_size = 0;
}

int mul_long_num(t_long_num *p, int i, int value, int remain)
{
    if ((p->num[i] *= value) >= MAX)
    {
        p->real_size = (p->real_size < i + 1)  ? i + 1 : p->real_size;
        mul_long_num(p, i + 1, value, p->num[i] / MAX);
        p->num[i] %= MAX;
    }
    else if (p->real_size > i)
            mul_long_num(p, i + 1, value, 0);
    p->num[i] += remain;
    return (1);
}

int sum_long_num(t_long_num *p, int i, LL_int value)
{
    int ost;

    ost = value / MAX;
    value %= MAX;
    if ((p->num[i] += value) >= MAX || ost)
    {
        p->real_size = (p->real_size < i + 1)  ? i + 1 : p->real_size;
        sum_long_num(p, i + 1, p->num[i] / MAX + ost);
        p->num[i] %= MAX;
    }
    return (1);
}