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

int		ft_pars_star_wid(t_type *type, int *val)
{
	
	*val =  va_arg(type->vl, int);
	if (type->width)
		type->error++;
	else
		type->star_w++;	
	if  (!type->width && (type->width = *val) < 0)
	{
		type->f_minus = 1;
		type->width *= -1;
	}
	return (1);	
}

int		ft_modifier_processing(t_type *type, const char *format, int count_skip)
{
	int		val;

	if (!type->star_w && format[0] == '*')
		return (ft_pars_star_wid(type, &val));
	else if ((val = ft_atoi(&format[0])))
	{
		if (type->star_w)
			type->error = 2;
		else
			type->width = val;		
		return (ft_intlen(val));
	}
	else if (format[0] == '.')
	{
		count_skip += ft_zero_skip(&format[1]);
		type->precision = format[1] == '*' ?
			va_arg(type->vl, int) : ft_atoi(&(format[1]));
		if (type->precision > 0 || format[1] == '*')
			count_skip += format[1] == '*' ? 1 : ft_intlen(type->precision);
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
	if (!type->error && ft_type(&format[i]))
	{
		type->type = format[i];
		return (i);
	}
	if (!ft_type(&format[i]))
		type->error = type->error ? 2 : -1;
	if(i > 0)
		type->error_array = ft_strsub(format, 0, i);
	return (type->error == 1 ? -i : --i);
}
