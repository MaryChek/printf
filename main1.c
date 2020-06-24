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
	type->star_w = 0;
	type->precision = 0;
	type->star_p = 0;
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
	type->error_array = NULL;
	type->dot = 0;
}

void	ft_create_typestruct(t_type *type)
{
	if ((type->types = ft_strdup("%diuoxXfcspeg\0")) == NULL)
		error(1, type->vl);
	if ((type->sizes = ft_strdup("hlL\0")) == NULL)
		error(1, type->vl);
	ft_type_cleaning(type);
	type->print = 0;
	type->error = 0;
}

void	ft_print_format(t_type *type)
{
	if (type->type == 'd' || type->type == 'i')
		type->print += ft_int_specifier(*type, va_arg(type->vl, LL_int));
	else if (type->type == 'u' || type->type == 'x' || type->type == 'X'
	|| type->type == 'o')
		type->print += ft_unsig_specifier(*type, va_arg(type->vl, ULL_int));
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

void	ft_clean_struct(t_type *type)
{
	ft_strdel(&type->types);
	ft_strdel(&type->sizes);
}

void	ft_print_error_arr(t_type *type)
{
	char 	*tmp;
	int		fl_dod;

	fl_dod = 0;
	tmp = type->error_array;
	type->print += ft_print_n_char(1, '%');
	while (tmp && *tmp)
	{
		if (*tmp == '*' && !fl_dod && type->star_w-- > 0)
			type->print += ft_putnbr_fd(type->width, 1);
		else if (*tmp == '*' && fl_dod && type->star_p-- > 0)
			type->print += ft_putnbr_fd(type->precision, 1);
		else
		{
			fl_dod += (*tmp == '.') ? 1 : 0;
			type->print += ft_print_n_char(1, *tmp);
		}
		tmp++;
	}
	ft_strdel(&(type->error_array));
}

int		ft_printf(const char *format, ...)
{
	t_type	type;
	int		i;

	i = -1;
	va_start(type.vl, format);
	ft_create_typestruct(&type);
	while (format[++i])
		if (format[i] == '%' && !type.error)
		{
			++i;
		  i  += ft_parse_type(&format[i], &type);
			if (type.type != '0')
				ft_print_format(&type);
			if (type.error_array && type.error == 2)
				ft_print_error_arr(&type);
			ft_type_cleaning(&type);
		}
		else
			type.print += ft_print_n_char(1, format[i]);
	va_end(type.vl);
	i = type.error < 0 ? -1 : type.print;
	ft_clean_struct(&type);
	return (i);
}

int		main()
{
	int a;
	double special;
	*((unsigned long *)(&special)) = 9218868437227405310;

	printf("\n\nTEST 0\n\n");

	a = printf("ORIG_PRINT---->%f", special);
	printf("|\nprint = %d(%d)\n\n", a, a - 15);
	a = ft_printf("MY_PRINT------>%f", special);
	printf("|\nmy print = %d(%d)\n\n", a, a - 15);

	// printf("\n\nTEST 1\n\n");

	// a = printf("ORIG_PRINT---->%#.x %#.0x", 0, 0);
	// printf("|\nprint = %d(%d)\n\n", a, a - 15);
	// a = ft_printf("MY_PRINT------>%#.x %#.0x", 0, 0);
	// printf("|\nmy print = %d(%d)\n\n", a, a - 15);

	// printf("\n\nTEST 2\n\n");
	
	// a = printf("ORIG_PRINT---->%.x %.0x", 0, 0);
	// printf("|\nprint = %d(%d)\n\n", a, a - 15);
	// a = ft_printf("MY_PRINT------>%.x %.0x", 0, 0);
	// printf("|\nmy print = %d(%d)\n\n", a, a - 15);

	// printf("\n\nTEST 3\n\n");
	
	// a = printf("ORIG_PRINT---->%5.x %5.0x", 0, 0);
	// printf("|\nprint = %d(%d)\n\n", a, a - 15);
	// a = ft_printf("MY_PRINT------>%5.x %5.0x", 0, 0);
	// printf("|\nmy print = %d(%d)\n\n", a, a - 15);

	// printf("\n\nTEST 4\n\n");
	
	// a = printf("ORIG_PRINT---->%.o %.0o", 0, 0);
	// printf("|\nprint = %d(%d)\n\n", a, a - 15);
	// a = ft_printf("MY_PRINT------>%.o %.0o", 0, 0);
	// printf("|\nmy print = %d(%d)\n\n", a, a - 15);

	// printf("\n\nTEST 5\n\n");
	
	// a = printf("ORIG_PRINT---->%5.o %5.0o", 0, 0);
	// printf("|\nprint = %d(%d)\n\n", a, a - 15);
	// a = ft_printf("MY_PRINT------>%5.o %5.0o", 0, 0);
	// printf("|\nmy print = %d(%d)\n\n", a, a - 15);

	// printf("\n\nTEST 6\n\n");
	
	// a = printf("ORIG_PRINT---->%.d %.0d", 0, 0);
	// printf("|\nprint = %d(%d)\n\n", a, a - 15);
	// a = ft_printf("MY_PRINT------>%.d %.0d", 0, 0);
	// printf("|\nmy print = %d(%d)\n\n", a, a - 15);

	// printf("\n\nTEST 7\n\n");
	
	// a = printf("ORIG_PRINT---->%5.d %5.0d", 0, 0);
	// printf("|\nprint = %d(%d)\n\n", a, a - 15);
	// a = ft_printf("MY_PRINT------>%5.d %5.0d", 0, 0);
	// printf("|\nmy print = %d(%d)\n\n", a, a - 15);
	
	/*printf("\nprint = %d\n", printf("% ", 5, 6));
	printf("\nmy print = %d\n\n", ft_printf("% ", 5, 6));
	printf("\nprint = %d\n", printf("%**3*d", 5, 6));
	printf("\nmy print = %d\n\n", ft_printf("%**3*d", 5, 6));
	printf("\nprint = %d\n", printf("%*3*d", 5, 6));
	printf("\nmy print = %d\n\n", ft_printf("%*3*d", 5, 6));
	printf("\nprint = %d\n", printf("%3*d", 5, 6));
	printf("\nmy print = %d\n\n", ft_printf("%3*d", 5, 6));
	printf("\nprint = %d\n", printf("%**3*t", 5, 6));
	printf("\nmy print = %d\n\n", ft_printf("%**3*t", 5, 6));
	printf("\nprint = %d\n", printf("%*3*t", 5, 6));
	printf("\nmy print = %d\n\n", ft_printf("%*3*t", 5, 6));
	printf("\nprint = %d\n", printf("%3*t", 5, 6));
	printf("\nmy print = %d\n\n", ft_printf("%3*t", 5, 6));*/

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