#include "ft_printf.h"

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

int		ft_print_float(t_float_param float_p, t_type type, int int_sign)
{
	t_long_num int_part;
	t_long_num fr_part;

	int_part.sign = int_sign;
	fr_part.sign = 0;

	/*int k = 79;// 63
	while (k >= 0)
	{
		if ((float_p.bits >> k) & 1)
			printf("1");
		else
			printf("0");
		k--;
		if (k == 78 || k == 63) //62 51
			printf(" ");
	}i*/

    ft_creat_integ_part_num(&int_part, &float_p);
	ft_creat_fract_part_num(&fr_part, &float_p);
	type.precision = (type.precision < 0 || !type.dot) ? 6 : type.precision;
	ft_roud_a_num(&int_part, &fr_part, float_p, type.precision);
	print_int_and_fr_parts(int_part, fr_part, &type, float_p.exp);
	return (type.print);
}

int		ft_print_char(char elem, t_type type)
{
	char c;

	if (type.width)
	{
		if (type.f_minus)
		{
			write(1, &elem, 1);
			ft_print_n_char(type.width - 1, ' ');
		}
		else
		{
			c = (type.f_null) ? '0' : ' ';
			ft_print_n_char(type.width - 1, c);
			write(1, &elem, 1);
		}
	}
	else
	{
		ft_putchar_fd(elem, 1);
		return (1);
	}
	return (type.width);
}

int		ft_print_string(char* elem, t_type type)
{
	int		count;
	char	*str;

	count = 0;
	if (elem == NULL)
		elem = ft_strdup("(null)\0");
	str = (type.precision >= 0 && type.dot) ? 
	ft_strsub(elem, 0, type.precision) : elem;
	if (type.f_minus)
	{
		ft_putstr_fd(str, 1);
		count += ft_put_space(str, type);
	}
	else
	{
		count += ft_put_space(str, type);
		ft_putstr_fd(str, 1);
	}
	if ((type.precision >= 0 && type.dot) || elem == NULL)
		ft_strdel(&str);
	return (count);
}

int		ft_print_pointer(void *elem, t_type type)
{
	UL_int	a;

	a = (UL_int)&(*elem);
	type.type = 'x';
	type.f_hash = 1;
	type.f_pointer = 1;
	return (ft_print_unsig(type, a));
}
