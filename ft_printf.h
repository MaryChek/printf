#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>
# include "libft/libft.h"
//# include <math.h>

typedef long long LL_int; // t_ll_int
typedef unsigned long long ULL_int; // t_ull_int
typedef unsigned long UL_int;

# define H 1
# define HH 2
# define L 3
# define LL 4
# define L_big 5

# define MAX 100000000

typedef struct  s_long_num
{
    int     num[100];
    char  real_size;
}               t_long_num;

typedef struct		s_type
{
	int			f_null;
	int			f_hash;
	int			f_minus;
	int			f_plus;
	int			f_space;
	int			f_pointer;
	int			width;
	int			precision;
	int			size;
	char		type;
	va_list		vl;
	unsigned	print;
	char		*types;
	char		*sizes;
	int			length;
	int			count_zero;
}					t_type;


int				ft_print_int(t_type type, LL_int elem);
int				ft_int_specifier(t_type type, LL_int num);

int				ft_print_unsig(t_type type, ULL_int elem);
int				ft_unsig_specifier(t_type type, ULL_int elem);

int				ft_print_float(double elem, t_type type);
int				print_integ_part(int *exp, __uint128_t bit, const int *sign, t_type *type);
void   			print_fract_part(int bit, int *exp, __uint128_t bits, t_type *type);
void    		init_array(t_long_num *p);
int				mul_long_num(t_long_num *p, int i, int value, int remain);
int				sum_long_num(t_long_num *p, int i, LL_int value);
void			print_array(t_long_num p, int sign, t_type *type);

int				ft_print_char(char elem, t_type type);

int				ft_print_string(char* elem, t_type type);

int				ft_print_pointer(void *elem, t_type type);

int				ft_parse_type(const char *format, t_type *type);
int				ft_skip_size(int size);
int				ft_zero_skip(const char *format);
void			error(int x, va_list vl);

int				ft_put_space(char* elem, t_type type);
int				ft_print_n_char(int num, char c);

int     power(int a, int i);
void	test_unsig_int_arg1(ULL_int num);
void	test_unsig_int_arg2(ULL_int num);
void	test_int_arg1(LL_int num);
void	test_int_arg2(LL_int num);
int		ft_printf(const char *format, ...);

#endif
