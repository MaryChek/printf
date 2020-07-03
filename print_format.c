#include "ft_printf.h"

int		ft_print_float(t_float_param float_p, t_type type, int int_sign)
{
	t_long_num int_part;
	t_long_num fr_part;

	int_part.sign = int_sign;
	fr_part.sign = 0;
	ft_creat_integ_part_num(&int_part, &float_p);
	ft_creat_fract_part_num(&fr_part, &float_p);
	type.precision = (type.precision < 0 || !type.dot) ? 6 : type.precision;
	if (fr_part.real_size != 0 && fr_part.num[fr_part.real_size] != 0)
		ft_round_a_num(&int_part, &fr_part, float_p, type.precision);
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
	char	*tmp;

	count = 0;
	tmp = (elem == NULL) ? ft_strdup("(null)\0") : elem;
	str = (type.precision >= 0 && type.dot) ?
	ft_strsub(tmp, 0, type.precision) : tmp;
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
