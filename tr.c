
void	print_int_array(t_long_num p, int sign, t_type *type)
{
    char    *str;
    int     size_num;
    int     ind_elem;

    ind_elem = p.real_size;
    while (ind_elem >= 0)
    {
        size_num = ft_intlen(p.num[ind_elem]);
        size_num += sign ? 1 : 0;
        if (ind_elem == p.real_size)
        {
            type->print += ft_count_zero_in_int_part(&p, *type, size_num);
            if (sign == 1)
            {
                p.num[p.real_size] *= -1;
                p.num[ind_elem] ? 0 : ft_print_n_char(1, '-');
            }
            else if (type->f_plus || type->f_space)
                type->print += type->f_plus ?
                ft_print_n_char(1, '+') : ft_print_n_char(1, ' ');
        }
        else if (size_num < 8)
            p.c_zero = 8 - size_num;
        ft_putstr_fd((str = ft_itoa(p.num[ind_elem--], p.c_zero)), 1);
        ft_memdel((void **)&str);
        type->print += p.c_zero + size_num;
        p.c_zero = 0;
    }
}

t_posit_to_round    ft_find_a_position_to_round(t_long_num fr_p, int exp, int precision)
{
    t_posit_to_round p_i;
    int     size;

    p_i.ind = fr_p.real_size;
    fr_p.c_zero = 52 - exp - 8 * fr_p.real_size - fr_p.fir_size; // functoin 52 - a - 8*b - c;
    size = fr_p.fir_size + fr_p.c_zero;
    if (precision > size)
    {
        size = precision - size - 1;
        p_i.regist = power(10, 7 - size % 8);
        p_i.ind = fr_p.real_size - size / 8 - 1;
    }
    else
        p_i.regist = power(10, size - precision);
    return (p_i);
}

void                ft_roud_a_num(t_long_num *int_p, t_long_num *fr_p, int exp, int precision)
{
    t_posit_to_round p_i;

    p_i = ft_find_a_position_to_round(*fr_p, exp, precision);
    if ((p_i.regist == 1 && p_i.ind && (fr_p->num[p_i.ind - 1] / (MAX / 10)) % 10 >= 5)
    || (p_i.regist > 1 && (fr_p->num[p_i.ind] / (p_i.regist / 10)) % 10 >= 5))
    {
        if (sum_long_short(fr_p, p_i.ind, p_i.regist))
            sum_long_short(int_p, 0, 1);
        if (fr_p->fir_size < ft_intlen(fr_p->num[fr_p->real_size]))
        {
            if (fr_p->c_zero)
                fr_p->c_zero--;
            else
            {
                if (!(fr_p->num[fr_p->real_size] %= power(10, fr_p->fir_size)))
                    fr_p->c_zero = fr_p->fir_size - 1;
                sum_long_short(int_p, 0, 1);
            }
        }
    }
}