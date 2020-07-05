#include "ft_printf.h"

int		ft_parse_bonus_part(const char *format, t_type *type)
{
	if (ft_strnstr(format, "{fd}", 4))
	{
		type->fd = va_arg(type->vl, int);
		return (4);
	}
	else if (ft_strnstr(format, "{/fd}", 5))
	{
		type->fd = 1;
		return (5);
	}
	return (0);
}