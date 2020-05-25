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
typedef long double L_Dub;

# define H 1
# define HH 2
# define L 3
# define LL 4
# define L_big 5

# define MAX 100000000

typedef struct	s_posit_to_round
{
	int		regist;
	int		ind;
}				t_posit_to_round;

typedef struct  s_float_param
{
    int			exp;
	__uint128_t	bits;
	int			bit;
	int			lst_mbit;
}               t_float_param;

typedef struct  s_long_num
{
    int     num[140];
    char	real_size;
	int		c_zero;
	int		size_fst;
	int		sign;
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
	int			star_w;
	int			precision;
	int			star_p;
	int			size;
	char		type;
	va_list		vl;
	unsigned	print;
	char		*types;
	char		*sizes;
	int			length;
	int			count_zero;
	int			error;
	char		*error_array;
	int         dot;
}					t_type;


int				ft_print_int(t_type type, LL_int elem);
int				ft_int_specifier(t_type type, LL_int num);

int				ft_print_unsig(t_type type, ULL_int elem);
int				ft_unsig_specifier(t_type type, ULL_int elem);

int				ft_float_specifier(t_type type);
int				ft_proc_bits_dub(t_float_param	*float_p, double elem);
int				ft_proc_bits_ldub(t_float_param	*float_p, L_Dub elem);
int				ft_print_float(t_float_param float_p, t_type type, int int_sign);
void			ft_creat_integ_part_num(t_long_num *int_p, t_float_param *float_p);
void			ft_creat_fract_part_num(t_long_num *fr_p, t_float_param *float_p);
void    		init_array(t_long_num *p);
int				mul_long_num(t_long_num *p, int i, int value, int remain);
int				sum_long_num(t_long_num *p, int i, t_long_num value, int remain);
int				sum_long_short(t_long_num *p, int i, int value);
void			print_fract_array(t_long_num p, int exp, t_type *type);
void			print_int_and_fr_parts(t_long_num in, t_long_num fr, t_type *type, int exp);
void    		ft_roud_a_num(t_long_num *int_p, t_long_num *fr_p, t_float_param fl_p, int precision);
void			ft_print_long_elem(t_long_num p, int *print, int index, int size_num);

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
