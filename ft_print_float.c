#include "ft_printf.h"

void	ft_creat_integ_part_num(t_long_num *int_p, t_float_param *float_p)
{
	int		i;
	int l;

	init_array(int_p);
	i = 0;
	if (float_p->exp >= 0)
	{
		int_p->num[0] = 1;
		while (i++ < (float_p->exp))
		{
			if (i == 16383)
				l = 1;
			mul_long_num(int_p, 0, 2, 0);
			if (((float_p->bits >> float_p->bit) & 1) && i <= float_p->lst_mbit)
				int_p->num[0] += 1;
			float_p->bit--;
		}
	}
	int_p->size_fst = ft_intlen(int_p->num[int_p->real_size]);
}

void	ft_creat_fract_part_num(t_long_num *fr_p, t_float_param *float_p)
{
	t_long_num	i;
	int			j;

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
}

int		ft_proc_bits_dub(t_float_param	*float_p, double elem)
{
	float_p->bits = *(__uint128_t *)(&elem);
	float_p->exp = ((float_p->bits >> 52) & 0x7ff) - 1023;
	float_p->bit = 51;
	float_p->lst_mbit = 52;
	return ((float_p->bits >> 63) & 1);
}

int		ft_proc_bits_ldub(t_float_param	*float_p, L_Dub elem)
{
	float_p->bits = *(__uint128_t *)(&elem);
	float_p->exp = ((float_p->bits >> 64) & 0x7fff) - 16383;
	float_p->bit = 62;
	float_p->lst_mbit = 64;
	return ((float_p->bits >> 79) & 1);
}

int		ft_float_specifier(t_type type)
{
	t_float_param	fl_p;
	int				sign;

	if (type.size == L_big)
	{
		sign = ft_proc_bits_ldub(&fl_p, va_arg(type.vl, L_Dub));
		return (ft_print_float(fl_p, type, sign));
	}
	else
	{
		sign = ft_proc_bits_dub(&fl_p, va_arg(type.vl, double));
		return (ft_print_float(fl_p, type, sign));
	}
}