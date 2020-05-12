#include "ft_printf.h"

void    ft_creat_integ_part_num(t_long_num *int_p, t_float_param *float_p)
{
    int     i;

    init_array(int_p);
    i = 0;
    if (float_p->exp >= 0)
    {
        int_p->num[0] = 1;
        while (i++ < (float_p->exp))
        {
            mul_long_num(int_p, 0, 2, 0);
            if (((float_p->bits >> float_p->bit) & 1) && i <= float_p->lst_mbit)
                int_p->num[0] += 1;
            float_p->bit--;
        }
    }
    int_p->size_fst = ft_intlen(int_p->num[int_p->real_size]);
}

void    ft_creat_fract_part_num(t_long_num *fr_p, t_float_param *float_p)
{
    t_long_num      i;
    int             j;

    j = float_p->exp;
    init_array(fr_p);
    init_array(&i);
    i.num[0] = 5;
    while (++j <= float_p->lst_mbit)
    {
        mul_long_num(fr_p, 0, 10, 0);
        if (j >= 0 && (!j || ((float_p->bits >> (float_p->bit)--) & 1)))
            sum_long_num(fr_p, 0, i, 0);
        mul_long_num(&i, 0, 5, 0);
    }
    fr_p->size_fst = ft_intlen(fr_p->num[fr_p->real_size]);
    /*int k = 63;
    while (k >= 0)
    {
        if ((bits >> k) & 1)
            printf("1");
        else
            printf("0");
        k--;
        if (k == 62 || k == 51)
            printf(" ");
    }*/
}