#include "ft_printf.h"

int		ft_count_zero_in_int_part(t_long_num *in, t_type type, int first_size)
{
	int		count;

	count = 0;
	type.precision += (type.precision || type.f_hash) ? 1 : 0;
	if (type.width)
	{
		count = type.width - 8 * in->real_size - first_size - type.precision;
		if ((type.f_space || type.f_plus) && !in->sign)
			count = (count - 1) > 0 ? --count : 0;
		if (count > 0)
		{
			if (type.f_null && !type.f_minus)
				in->c_zero = count;
			else if ((type.f_null && type.f_minus) || !type.f_null)
				ft_print_n_char(count, ' ');
		}
	}
	return (count);
}

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
		c = (type.f_null && !type.f_minus) ? '0' : ' ';
		count += ft_print_n_char(type.width - stlen, c);
	}
	count += ft_strlen(elem);
	return (count);
}

void	ft_put_prefix_of_float(t_long_num *in, int index, t_type *type)
{
	if (in->sign == 1)
	{
		in->num[in->real_size] *= -1;
		in->num[index] ? 0 : ft_print_n_char(1, '-');
	}
	else if (type->f_plus || type->f_space)
		type->print += type->f_plus ?
		ft_print_n_char(1, '+') : ft_print_n_char(1, ' ');
}

void	ft_print_long_num(t_long_num in, t_long_num fr, t_type *type, int exp)
{
	int		size_num;
	int		ind_elem;

	ind_elem = in.real_size;
	ft_print_long_elem(in, &(type->print), ind_elem--, in.size_fst);
	while (ind_elem >= 0)
	{
		if ((size_num = ft_intlen(in.num[ind_elem])) < 8)
			in.c_zero = 8 - size_num;
		ft_print_long_elem(in, &(type->print), ind_elem--, size_num);
		in.c_zero = 0;
	}
	if (type->precision || type->f_hash)
		type->print += ft_print_n_char(1, '.');
	if (type->precision)
		print_fract_array(fr, exp, type);
}

void	print_int_and_fr_parts(t_long_num in, t_long_num fr, t_type *type, int exp)
{
	in.size_fst += in.sign ? 1 : 0;
	if (type->f_minus)
	{
		ft_put_prefix_of_float(&in, in.real_size, type);
		ft_print_long_num(in, fr, type, exp);
		type->print += ft_count_zero_in_int_part(&in, *type, in.size_fst);
	}
	else 
	{
		type->print += ft_count_zero_in_int_part(&in, *type, in.size_fst);
		ft_put_prefix_of_float(&in, in.real_size, type);
		ft_print_long_num(in, fr, type, exp);
	}
}

void	print_fract_array(t_long_num p, int exp, t_type *type)
{
	char	*str;
	int		size_num;
	int		ind_elem;
	int		n_char;
	int		precition;

	ind_elem = p.real_size;
	precition = type->precision;
	type->print += precition;
	while (ind_elem >= 0 && precition > 0)
	{
		n_char = precition;
		size_num = ft_intlen(p.num[ind_elem]);
		if (ind_elem != p.real_size && size_num < 8)
			p.c_zero = 8 - size_num;
		str = ft_itoa(p.num[ind_elem--], p.c_zero);
		n_char = ft_put_n_line_char(str, n_char);
		precition -= n_char; 
		ft_memdel((void **)&str);
		p.c_zero = 0;
	}
	if (precition > 0)
		ft_print_n_char(precition, '0');
}

int     power(int a, int i)
{
	int		b;

	b = 1;
	if (i == 0)
		return (1);
	while (i-- > 0)
		b *= a;
	return (b);
}
