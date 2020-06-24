#include "ft_printf.h"

void	ft_print_long_elem(t_long_num p, unsigned *print, int index, int size_num)
{
	char	*str;

	ft_putstr_fd((str = ft_itoa(p.num[index], p.c_zero)), 1);
	ft_memdel((void **)&str);
	*print += p.c_zero + size_num;
}

void	init_array(t_long_num *p)
{
	int		i;

	i = -1;
	while (++i < 100)
		p->num[i] = 0; 
	p->real_size = 0;
	p->c_zero = 0;
}

int		mul_long_num(t_long_num *p, int i, int value, int remain)
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

int		sum_long_num(t_long_num *p, int i, t_long_num value, int remain)
{
	if ((p->num[i] += value.num[i] + remain) >= MAX)
	{
		p->real_size = (p->real_size < i + 1)  ? i + 1 : p->real_size;
		sum_long_num(p, i + 1, value, p->num[i] / MAX);
		p->num[i] %= MAX;
	}
	else if (value.real_size > i)
	{
		p->real_size = (p->real_size < i + 1)  ? i + 1 : p->real_size;
		sum_long_num(p, i + 1, value, 0);
	}
	return (1);
}

int		sum_long_short(t_long_num *p, int i, int value)
{
	int		num;

	if ((p->num[i] += value) >= MAX)
	{
		num = p->num[i] / MAX;
		p->num[i] %= MAX;
		if (i < p->real_size || p->c_zero)
		{
			if (p->real_size < i + 1)
			{
				p->real_size++;
				p->c_zero -= p->c_zero ? 1 : 0;
			}
			return (sum_long_short(p, i + 1, num));
		}
		else
			return (1);
	}
	return (0);
}

t_posit_to_round	ft_find_a_position_to_round(t_long_num fr_p, int exp, int precision)
{
	t_posit_to_round	p_i;
	int					size;

	p_i.ind = fr_p.real_size;
	size = fr_p.size_fst + fr_p.c_zero;
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

void				ft_lift_the_int_part(t_long_num *int_p, t_long_num *fr_p, int regist)
{
	fr_p->num[fr_p->real_size] %= power(10, fr_p->size_fst);
	if (!(fr_p->num[fr_p->real_size] / regist))
		fr_p->c_zero = fr_p->size_fst - 1;
	sum_long_short(int_p, 0, 1);
}

int					ft_fr_count_zero(t_long_num fr_p, t_float_param fl_p)
{
	int		count;

	count = fl_p.lst_mbit - fl_p.exp -
		8 * fr_p.real_size - fr_p.size_fst;
	return (count);
}

void				ft_roud_a_num(t_long_num *int_p, t_long_num *fr_p, t_float_param fl_p, int precision)
{
	t_posit_to_round	p_i;

	fr_p->c_zero = ft_fr_count_zero(*fr_p, fl_p);
	p_i = ft_find_a_position_to_round(*fr_p, fl_p.exp, precision);
	if ((p_i.regist == 1 && p_i.ind &&
			(fr_p->num[p_i.ind - 1] / (MAX / 10)) % 10 >= 5)
	|| (p_i.regist > 1 &&
			(fr_p->num[p_i.ind] / (p_i.regist / 10)) % 10 >= 5))
	{
		if (sum_long_short(fr_p, p_i.ind, p_i.regist))
			sum_long_short(int_p, 0, 1);
		if (fr_p->size_fst < ft_intlen(fr_p->num[fr_p->real_size]))
		{
			if (fr_p->c_zero)
				fr_p->c_zero--;
			else
				ft_lift_the_int_part(int_p, fr_p, p_i.regist);
		}
	}
}
