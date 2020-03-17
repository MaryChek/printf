#include "ft_printf.h"

void	ft_parse_size(const char *format, t_type *type)
{
	if (format[0] == 'h' && format[1] != 'h')
		type->size = H;
	else if (format[0] == 'h' && format[1] == 'h')
		type->size = HH;
	else if (format[0] == 'l' && format[1] != 'l')
		type->size = L;
	else if (format[0] == 'l' && format[1] == 'l')
		type->size = LL;
	else if (format[0] == 'L')
		type->size = L_big;
}

int		ft_modifier_processing(t_type *type, const char *format, int count_skip)
{
	int		val;

	if ((val = ft_atoi(&format[0])) != 0) //добавить *
	{
		type->width = val;
		count_skip = ft_intlen(type->width);
	}
	else if (format[0] == '.')
	{
		count_skip += ft_zero_skip(&format[1]);
		type->precision = ft_atoi(&(format[1]));
		if (type->precision != 0)
			count_skip += ft_intlen(type->precision);
	}
	else
	{
		val = 0;
		while (format[0] != type->sizes[val] && type->sizes[val])
			++val;
		if (type->sizes[val] != '\0')
			ft_parse_size(&format[0], type);
		count_skip += ft_skip_size(type->size);
	}
	return (count_skip);
}

int		ft_parse_format(const char *format, t_type *type)
{
	int		i;
	int		count_skip;

	i = 0;
	count_skip = 1;
	if (format[i] == '#' && type->f_null == 0)
		type->f_hash = 1;
	else if (format[i] == '0' && type->f_null == 0)
		type->f_null = 1;
	else if (format[i] == '-' && type->f_minus == 0)
		type->f_minus = 1;
	else if (format[i] == '+' && type->f_plus == 0)
		type->f_plus = 1;
	else if (format[i] == ' ' && type->f_space == 0)
		type->f_space = 1;
	else if (format[i] != '0')
		return (ft_modifier_processing(type, format, count_skip));
	return (count_skip);
}

int		ft_type(const char *format)
{
	if (*format == 'd' || *format == 'i' || *format == 'u' 
		|| *format == 'o' || *format == 'x' || *format == 'X' 
		|| *format == 'f' || *format == 'c' || *format == 'p'
		 || *format == 'e' || *format == 'g' || *format == 's' 
		|| *format == '%')
		return (1);
	else
		return (0);
}

int		ft_parse_type(const char *format, t_type *type)
{
	int		i;

	i = 0;
	while (format[i] && !ft_type(&format[i]))
	{
		if (!ft_type(&format[i]))
			i += ft_parse_format(&format[i], type);
	}
	if (ft_type(&format[i]))
	{
		type->type = format[i];
		return (i);
	}
	return (-1);
}
