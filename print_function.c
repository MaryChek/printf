#include "ft_printf.h"

int		ft_print_n_char(int num, char c)
{
	int count;

	count = num;
	while (num-- > 0)
		write(1, &c, 1);
	return (count);
}

int		ft_put_space(char* elem, t_type type)
{
	int stlen;
	char c;
	int count;

	count = 0;
	if (type.width > 0 && type.width > (stlen = ft_strlen(elem)))
	{
		c = (type.f_null) ? '0' : ' ';
		count += ft_print_n_char(type.width - stlen, c);
	}
	count += ft_strlen(elem);
	return (count);
}

void	print_array(t_long_num p, int sign, t_type *type)
{
    char    *str;
    int     count_zero;
    int     size_num;
    int     ind_elem;

    if (sign == 1)
        write(1, "-", 1);
    ind_elem = p.real_size;
    while (ind_elem >= 0)
    {
        count_zero = 0;
        size_num = ft_intlen(p.num[ind_elem]);
        if (size_num < 8 && ind_elem < p.real_size)
            count_zero = 8 - size_num;
        ft_putstr_fd((str = ft_itoa(p.num[ind_elem--], count_zero)), 1);
        ft_memdel((void **)&str);
        type->print += count_zero + size_num;
    }
}

int     power(int a, int i)
{
    if (i == 0)
        return (1);
    while (i-- > 0)
        a *= a;
    return (a);
}
