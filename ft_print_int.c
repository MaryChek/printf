#include "ft_printf.h"

int		print_spase(t_type *type, const LL_int *elem)
{
	int i;
	int count;

	count = 0;
	if (type->precision > type->length - (*elem < 0 ? 1 : 0))
		i = type->width - type->precision;
	else
		i = type->width - type->length;
	if (i >= 0)
	{
		if (((type->f_plus || type->f_space) && *elem > 0)
		|| (*elem < 0 && (type->precision > (type->length - 1)))
		|| ((type->f_plus || type->f_space) && *elem >= 0 && type->precision))
			i--;
		if ((type->precision < 0 && type->f_null) && !type->f_minus)
			type->count_zero += i;
		else
			count += ft_print_n_char(i, ' ');
	}
	return (count);
}

int		print_precision_and_elem(t_type *type, const LL_int *elem)
{
	int i;
	int count;
	char *str;

	count = 0;
	i = type->precision - type->length + ((*elem < 0) ? 1 : 0);
	if (*elem > 0 || (type->precision && !*elem))
	{
		if (type->f_plus)
			count += ft_print_n_char(1, '+');
		else if (type->f_space)
			count += ft_print_n_char(1, ' ');
	}
	if (i > 0)
		type->count_zero += i;
	if (type->precision || *elem)
	{
		ft_putstr_fd((str = ft_itoa_base(*elem, 10, type->count_zero)), 1);
		ft_strdel(&str);
	}
	if (!*elem && !type->precision)
		if (type->f_plus || type->f_space || type->f_minus || type->f_null
		|| (!type->f_plus && !type->f_space && !type->f_minus && type->width))
			count += ft_print_n_char(1, type->f_plus ? '+' : ' ');
	return (count + type->count_zero);
}

int		ft_print_int(t_type type, LL_int elem)
{
	int count;

	count = 0;
	type.length = ft_intlen(elem);
	if (type.f_minus)
	{
		count += print_precision_and_elem(&type, &elem);
		count += print_spase(&type, &elem);
	}
	else
	{
		count += print_spase(&type, &elem);
		count += print_precision_and_elem(&type, &elem);
	}
	if (type.precision || (!type.precision && elem))
		return (count + type.length);
	else
		return (count);
}

int		ft_int_specifier(t_type type, LL_int elem)
{
	if (type.size == H)
		return (ft_print_int(type, (short)elem));
	else if (type.size == HH)
		return (ft_print_int(type, (char)elem));
	else if (type.size == L || type.size == LL)
		return (ft_print_int(type, (long int)elem));
	else
		return (ft_print_int(type, (int)elem));
}
