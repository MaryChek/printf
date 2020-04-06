#include "ft_printf.h"

int		ft_print_float(double elem, t_type type)
{
	__uint128_t	bits;
	int 		exp;
	int			sign;
	int			bit;

	bits = *(__uint128_t *)(&elem);
	exp = ((bits >> 52) & 0x7ff) - 1023;
    sign = (bits >> 63) & 1;
    bit = print_integ_part(&exp, bits, &sign, &type);
	write(1, ".", 1);
	print_fract_part(bit, &exp, bits, &type);
	return 0;
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
	if (elem != NULL)
		str = type.precision >= 0 ? ft_strsub(elem, 0, type.precision) : elem;
	else
		str = type.precision >= 0 ? ft_strsub("(null)\0", 0, type.precision) : ft_strdup("(null)\0");
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
	(type.precision >= 0 || elem == NULL) ? ft_strdel(&str) : 0;
	return (count);
}

int		ft_print_pointer(void *elem, t_type type)
{
	UL_int	a;

	if (elem == NULL)
		return (ft_print_string("(nil)", type));
	a = (UL_int)&(*elem);
	type.type = 'x';
	type.f_hash = 1;
	type.f_pointer = 1;
	return (ft_print_unsig(type, a));
}
