#include "ft_printf.h"

int		print_n_char(int num, char c)
{
	int count;

	count = num;
	while (num-- > 0)
		write(1, &c, 1);
	return (count);
}

int		ft_print_float(float elem, t_type type)
{
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
			print_n_char(type.width - 1, ' ');
		}
		else
		{
			c = (type.f_null) ? '0' : ' ';
			print_n_char(type.width - 1, c);
			write(1, &elem, 1);
		}
	}
	else
	{
		ft_putchar(elem);
		return (1);
	}
	return (type.width);
}

int		ft_put_space(char* elem, t_type type)
{
	int stlen;
	char c;
	int count;

	count = 0;
	if (type.width > 0 && type.width > (stlen = ft_strlen(elem)))
	{
		c = (type.f_null) ? '0' : ' ';
		count += print_n_char(type.width - stlen, c);
	}
	count += ft_strlen(elem);
	return (count);
}

int		ft_print_string(char* elem, t_type type)
{
	int count;
	char *str;

	count = 0;
	if (elem != NULL)
		str = type.precision >= 0 ? ft_strsub(elem, 0, type.precision) : elem;
	else
		str = type.precision >= 0 ? ft_strsub("(null)\0", 0, type.precision) : ft_strdup("(null)\0");
	if (type.f_minus)
	{
		ft_putstr(str);
		count += ft_put_space(str, type);
	}
	else
	{
		count += ft_put_space(str, type);
		ft_putstr(str);
	}
	(type.precision >= 0 || elem == NULL) ? ft_strdel(&str) : 0;
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

