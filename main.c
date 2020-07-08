/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtacos <rtacos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/30 12:24:13 by dhojt             #+#    #+#             */
/*   Updated: 2020/07/08 20:27:39 by rtacos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include <stdio.h>
#include <fcntl.h>

#define FTPF_LDBL_BYTE5(x) ((short *)(&x))[4]


int				main(void)
{
	// int a;
	// printf("\n\nTEST 0\n\n");

	// // long double x = __DBL_MAX__ + __DBL_MAX__;
	// // // printf("%Lf\n\n", x);
	// // ft_printf("%s\n", NULL);

	// long double special;
	// *((unsigned long *)(&special)) = 0ull;
	// FTPF_LDBL_BYTE5(special) = 0;

	// int fd;
	// fd = open("t", O_WRONLY);
	// int x = 100500;
	// int* ptr_x = &x;

	// //a = printf("ORIG_PRINT---->%s", NULL);
	// //printf("|\nprint = %d(%d)\n\n", a, a - 15);
	// a = ft_printf("MY_PRINT------>%s", NULL);
	//printf("|\nmy print = %d(%d)\n\n", a, a - 15);
	double a;

	a = 0.12;
	ft_printf("%-100.101f", a);
	return 0;
}
