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

int				main(void)
{
	int a;
	printf("\n\nTEST 0\n\n");

	long double x = __DBL_MAX__ + __DBL_MAX__;
	// printf("%Lf\n\n", x);
	a = printf("ORIG_PRINT---->%Lf", x);
	printf("|\nprint = %d(%d)\n\n", a, a - 15);
	a = ft_printf("MY_PRINT------>%Lf",x);
	printf("|\nmy print = %d(%d)\n\n", a, a - 15);
}
