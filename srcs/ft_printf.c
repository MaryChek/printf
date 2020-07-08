/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtacos <rtacos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 20:25:39 by rtacos            #+#    #+#             */
/*   Updated: 2020/07/08 20:47:07 by rtacos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	error(int x, va_list vl)
{
	if (x == 1)
		write(1, "Memory allocation error\n", 24);
	va_end(vl);
	exit(1);
}

void	ft_print_format(t_type *type)
{
	if (type->type == 'd' || type->type == 'i')
		type->print += ft_int_specifier(*type, va_arg(type->vl, t_ll_int));
	else if (type->type == 'u' || type->type == 'x' || type->type == 'X'
	|| type->type == 'o')
		type->print += ft_unsig_specifier(*type, va_arg(type->vl, t_ull_int));
	else if (type->type == 'f' || type->type == 'e' || type->type == 'g')
		type->print = ft_float_specifier(*type);
	else if (type->type == 'c')
		type->print += ft_print_char(va_arg(type->vl, int), *type);
	else if (type->type == '%')
		type->print += ft_print_char('%', *type);
	else if (type->type == 's')
		type->print += ft_print_string(va_arg(type->vl, char*), *type);
	else if (type->type == 'p')
		type->print += ft_print_pointer(va_arg(type->vl, void *), *type);
}

int		ft_printf(const char *format, ...)
{
	t_type		type;
	int			i;

	i = -1;
	va_start(type.vl, format);
	ft_create_typestruct(&type);
	while (format[++i])
		if (format[i] == '{' && !type.fall)
			i += ft_parse_bonus_part(&format[i], &type);
		else if (format[i] == '%' && !type.fall)
		{
			++i;
			i += ft_parse_type(&format[i], &type);
			if (type.type != '0')
				ft_print_format(&type);
			ft_type_cleaning(&type);
		}
		else
		{
			type.print += ft_print_n_char(1, format[i], type.fd);
			type.fall = 0;
		}
	va_end(type.vl);
	ft_del_struct(&type);
	return (type.print);
}
