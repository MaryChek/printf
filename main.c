/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtacos <rtacos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/30 12:24:13 by dhojt             #+#    #+#             */
/*   Updated: 2020/07/05 20:44:43 by rtacos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <fcntl.h>

#define FTPF_LDBL_BYTE5(x) ((short *)(&x))[4]


int				main(void)
{
	int a;
	printf("\n\nTEST 0\n\n");

	// long double x = __DBL_MAX__ + __DBL_MAX__;
	// // printf("%Lf\n\n", x);
	// ft_printf("%s\n", NULL);

	long double special;
	*((unsigned long *)(&special)) = 0ull;
	FTPF_LDBL_BYTE5(special) = 0;
	wchar_t wz[3] = L"@@";

	int fd;
	fd = open("t", O_WRONLY);

	// a = printf("ORIG_PRINT---->i see it{fd}i can't see{/fd}", fd);
	// printf("|\nprint = %d(%d)\n\n", a, a - 15);
	a = ft_printf("MY_PRINT------>i see it{fd}i can't see{/fd} open file t", fd);
	printf("|\nmy print = %d(%d)\n\n", a, a - 15);

}

// int		main()
//                       DISABLE_TEST:
// notinsubject_moul_::G,D,e,a ;
// bonus_notrequired_::g,e ;
// bonus_moul_::e,g ;
// bonus_::g,e ;
// bonus_notrequired_f_reserved_values_::inf,ninf,nan ;
// notinsubject_f_L_reserved_values_::inf,nan,ninf ;
// argnum_notinsubject
// notinsubject_moul_widechar
// {
// 	int a;
// 	double special;
// 	*((unsigned long *)(&special)) = 9218868437227405310;

// 	// printf("\n\nTEST 0\n\n");

// 	a = printf("ORIG_PRINT---->%Lf", __LDBL_MAX__ - 100000000000000000000.0);
// 	printf("|\nprint = %d(%d)\n\n", a, a - 15);
// 	a = ft_printf("MY_PRINT------>%Lf", __LDBL_MAX__ - 100000000000000000000.0);
// 	printf("|\nmy print = %d(%d)\n\n", a, a - 15);

	// printf("\n\nTEST 1\n\n");

	// a = printf("ORIG_PRINT---->%#.x %#.0x", 0, 0);
	// printf("|\nprint = %d(%d)\n\n", a, a - 15);
	// a = ft_printf("MY_PRINT------>%#.x %#.0x", 0, 0);
	// printf("|\nmy print = %d(%d)\n\n", a, a - 15);

	// printf("\n\nTEST 2\n\n");
	
	// a = printf("ORIG_PRINT---->%- 15.8s %.0x", "ghjkjhgfghjk  ninimoni iomoiuhunoi", 0);
	// printf("|\nprint = %d(%d)\n\n", a, a - 15);
	// a = ft_printf("MY_PRINT------>%- 15.8s %.0x", "ghjkjhgfghjk  ninimoni iomoiuhunoi", 0);
	// printf("|\nmy print = %d(%d)\n\n", a, a - 15);

	// printf("\n\nTEST 3\n\n");
	
	// a = printf("ORIG_PRINT---->%#5.f %5.0x", 15480.588151, 0);
	// printf("|\nprint = %d(%d)\n\n", a, a - 15);
	// a = ft_printf("MY_PRINT------>%#5.f %5.0x", 15480.588151, 0);
	// printf("|\nmy print = %d(%d)\n\n", a, a - 15);

	// printf("\n\nTEST 4\n\n");
	
	// a = printf("ORIG_PRINT---->%.o %.0o", 0, 2651628);
	// printf("|\nprint = %d(%d)\n\n", a, a - 15);
	// a = ft_printf("MY_PRINT------>%.o %.0o", 0, 2651628);
	// printf("|\nmy print = %d(%d)\n\n", a, a - 15);

	// printf("\n\nTEST 5\n\n");
	// char y = 'j';
	// char *t = &y;
	// a = printf("ORIG_PRINT---->%#5.p %5.0o", t, 0);
	// printf("|\nprint = %d(%d)\n\n", a, a - 15);
	// a = ft_printf("MY_PRINT------>%#5.p %5.0o", t, 0);
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
	
	// printf("\nprint = %d\n", printf("% ", 5, 6));
	// printf("\nmy print = %d\n\n", ft_printf("% ", 5, 6));
	// printf("\nprint = %d\n", printf("%**3*d", 5, 6));
	// printf("\nmy print = %d\n\n", ft_printf("%**3*d", 5, 6));
	// printf("\nprint = %d\n", printf("%*3*d", 5, 6));
	// printf("\nmy print = %d\n\n", ft_printf("%*3*d", 5, 6));
	// printf("\nprint = %d\n", printf("%3*d", 5, 6));
	// printf("\nmy print = %d\n\n", ft_printf("%3*d", 5, 6));
	// printf("\nprint = %d\n", printf("%**3*t", 5, 6));
	// printf("\nmy print = %d\n\n", ft_printf("%**3*t", 5, 6));
	// printf("\nprint = %d\n", printf("%*3*t", 5, 6));
	// printf("\nmy print = %d\n\n", ft_printf("%*3*t", 5, 6));
	// printf("\nprint = %d\n", printf("%3*t", 5, 6));
	// printf("\nmy print = %d\n\n", ft_printf("%3*t", 5, 6));

// }

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