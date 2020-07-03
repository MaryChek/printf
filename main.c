/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <dhojt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/30 12:24:13 by dhojt             #+#    #+#             */
/*   Updated: 2018/06/30 12:29:15 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

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

	a = printf("ORIG_PRINT---->%.1f", -2.56);
	printf("|\nprint = %d(%d)\n\n", a, a - 15);
	a = ft_printf("MY_PRINT------>%.1f", -2.56);
	printf("|\nmy print = %d(%d)\n\n", a, a - 15);

}
