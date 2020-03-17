#include "ft_printf.h"
#include <limits.h>

void	error(int x, va_list vl)
{
	if (x == 1)
		write(1, "Memory allocation error\n", 24);
	va_end(vl);
	exit(1);
}

void	ft_type_cleaning(t_type *type)
{
	type->width = 0;
	type->precision = -1;
	type->size = 0;
	type->type = '0';
	type->length = 0;
	type->count_zero = 0;
	type->f_plus = 0;
	type->f_space = 0;
	type->f_minus = 0;
	type->f_hash = 0;
	type->f_null = 0;
	type->f_pointer = 0;
}

void	ft_create_typestruct(t_type *type)
{
	if ((type->types = ft_strdup("%diuoxXfcspeg\0")) == NULL)
		error(1, type->vl);
	if ((type->sizes = ft_strdup("hlL\0")) == NULL)
		error(1, type->vl);
	ft_type_cleaning(type);
	type->print = 0;
}

void	ft_print_format(t_type *type)
{
	if (type->type == 'd' || type->type == 'i')
		type->print += ft_int_specifier(*type, va_arg(type->vl, LL_int));
	else if (type->type == 'u' || type->type == 'x' || type->type == 'X'
	|| type->type == 'o')
		type->print += ft_unsig_specifier(*type, va_arg(type->vl, ULL_int));
	else if (type->type == 'f' || type->type == 'e' || type->type == 'g')
		type->print += ft_print_float(va_arg(type->vl, double), *type);
	else if (type->type == 'c')
		type->print += ft_print_char(va_arg(type->vl, int), *type);
	else if (type->type == '%')
		type->print += ft_print_char('%', *type);
	else if (type->type == 's')
		type->print += ft_print_string(va_arg(type->vl, char*), *type);
	else if (type->type == 'p')
		type->print += ft_print_pointer(va_arg(type->vl, void*), *type);
}

void	ft_clean_struct(t_type *type)
{
	ft_strdel(&type->types);
	ft_strdel(&type->sizes);
}

int		ft_printf(const char *format, ...)
{
	t_type	type;
	int		i;

	i = -1;
	va_start(type.vl, format);
	ft_create_typestruct(&type);
	while (format[++i])
		if (format[i] == '%')
		{
			++i;
			i += ft_parse_type(&format[i], &type);
			if (type.type != '0')
				ft_print_format(&type);
			ft_type_cleaning(&type);
		}
		else
		{
			write(1, &format[i], 1);
			type.print++;
		}
	va_end(type.vl);
	i = type.print;
	ft_clean_struct(&type);
	return (i);
}

// int		main()
// {
// 	char	*types;
// // // 	// char	c;

// // // 	// c = '0';
// // // 	// types = "abcdefghijkl";
// // // 	// static char *s_hidden = "hi low\0don't print me lol\0";
// // // 	// int *t = &c;
// // // 	// printf("test1 %d\n", ft_printf("%-7i", 0));

// 	// test_unsig_int_arg1(4587);
// 	// test_unsig_int_arg2(4587);
// 	// test_int_arg1(0);
// 	// // test_int_arg2(0);
// 	// double dub = 858248238237248934834899.94848383;
// 	// double dub2 =			 858248238237248932282368.000000;
// 	printf("\n%d\n", printf("%f", dub2));

// 	// printf("\n%d\n", ft_printf("this %u number", 17));
// 	// printf("\n%d", printf("@moulitest: %#.x %#.0x", 0, 0));
// 	// int *b = &a;
// 	// ft_printf("%020p\n", &a10);
// 	// printf("%020p\n", &a10);
// 	// printf("%X\n",b);
// 	// printf("test my %d\n", printf("%.6p", types));
// 	// printf("test my %d\n", ft_printf("%.6i", -3));
// 	// printf("test2 %d\n", ft_printf("%-7.5d\n", -1234567));
// 	// printf("%d\n", printf("%#010.5o\n", 1254));
// 	// printf("%d\n", printf("%0#10.5o\n", 1254));
// 	// // printf("test2 %d\n", ft_printf("%d\n", H));
// 	// printf("%d\n", printf("%# 10.5o\n", 1254));
// 	// printf("%d\n", printf("% #10.5o\n", 1254));
// 	// // printf("%d\n", ft_printf("print %-0006.05s, %0006s\n", types, types));
// 	// printf("%d\n", printf("%#+10.5o\n", 1254));
// 	// printf("%d\n", printf("%+#10.5o\n", 1254));
// 	// // printf("%d\n", ft_printf("%5%3%4%4%2%"));
// 	// printf("%d\n", printf("%#-10.5o\n", 1254));
// 	// printf("%d\n", printf("%-#10.5o\n", 1254));
// 	// printf("%d\n", printf("%d\n", printf("%-10s is a string\n", "")));
// 	// printf("%#.5o", 5263);
// 	// ft_printf("%#.5o", 5263);
// 	return (0);
// }