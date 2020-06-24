#include "ft_printf.h"

int		ft_parse_base(int *base, char type)
{
	if (type == 'X')
	{
		*base = 16;
		return (1);
	}
	else if (type == 'x')
		*base = 16;
	else if (type == 'o')
		*base = 8;
	else
		*base = 10;
	return (0);

}
int		ft_print_zero_elem(t_type *type)
{
	int count;

	count = 0;
	if (type->type == 'o' && type->f_hash)
		ft_print_n_char(1, '0');
	else if (type->width && (type->type == 'o' || type->type == 'x' || type->type == 'X'))
		ft_print_n_char(1, ' ');
	else if (type->f_plus || type->f_space || type->f_minus || type->f_null
		|| (!type->f_plus && !type->f_space && !type->f_minus && type->width))
			count += ft_print_n_char(1, type->f_plus ? '+' : ' ');
	else
		type->length = 0;
	return (count);
}

int		print_unsig_spase(t_type *type, const ULL_int *elem)
{
	int i;
	int count;

	count = 0;
	if (type->precision > type->length)
		i = type->width - type->precision;
	else
		i = type->width - type->length;
	if (i > 0)
	{
		if (type->f_pointer || (type->f_hash && (type->type == 'x' || type->type == 'X') && *elem))
			i -= 2;
		if (type->f_hash && type->type == 'o' && *elem && type->precision <= type->length)
			--i;
		if ((!type->dot && type->f_null) && !type->f_minus)
			type->count_zero += i;
		else
			count += ft_print_n_char(i, ' ');
	}
	return (count > 0 ? count : 0);
}

int		print_unsig_precision(t_type *type, const ULL_int *elem, int base, int reg)
{
	int i;
	int count;
	char *str;

	count = 0;
	i = type->precision - type->length;
	type->count_zero += (i > 0) ? i : 0;
	if (!type->dot || type->precision > 0 || *elem || type->f_pointer)
	{
		if (type->f_pointer || (type->f_hash && (type->type == 'x' || type->type == 'X') && *elem))
		{
			type->type == 'x' ? write(1, "0x", 2) : write(1, "0X", 2);
			count += 2;
		}
		else if (type->f_hash && type->type == 'o' && *elem && type->precision <= type->length)
			count += ft_print_n_char(1, '0');
		if (!type->f_pointer || *elem || type->precision || !type->dot)
		{
			ft_putstr_fd((str = ft_itoa_unsig_base(*elem, base, type->count_zero, reg)), 1);
			ft_strdel(&str);
		}
	}
	if (!*elem && !type->precision && type->dot)
		ft_print_zero_elem(type);
	return (count + type->count_zero);
}

int		ft_print_unsig(t_type type, ULL_int elem)
{
	int count;
	int base;
	int reg;

	count = 0;
	reg = ft_parse_base(&base, type.type);
	type.length = ft_base_intlen(elem, base);
	if (type.f_minus)
	{
		count += print_unsig_precision(&type, &elem, base, reg);
		count += print_unsig_spase(&type, &elem);
	}
	else
	{
		count += print_unsig_spase(&type, &elem);
		count += print_unsig_precision(&type, &elem, base, reg);
	}
	return (count + type.length);
}

int		ft_unsig_specifier(t_type type, ULL_int elem)
{
	if (type.size == H)
		return (ft_print_unsig(type, (unsigned short)elem));
	else if (type.size == HH)
		return (ft_print_unsig(type, (unsigned char)elem));
	else if (type.size == L || type.size == LL)
		return (ft_print_unsig(type, (unsigned long int)elem));
	else
		return (ft_print_unsig(type, (unsigned int)elem));
}