#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>
# include "libft/libft.h"
# include <math.h>

typedef long long LL_int; // t_ll_int
typedef unsigned long long ULL_int; // t_ull_int
typedef unsigned long UL_int;

# define H 1
# define HH 2
# define L 3
# define LL 4
# define L_big 5

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
	// char		*result;
}					t_type;


int				ft_print_int(t_type type, LL_int elem);
int				ft_print_float(float elem, t_type type);
int				ft_print_char(char elem, t_type type);
int				ft_print_string(char* elem, t_type type);
int				ft_print_pointer(void* elem, t_type type);
int				ft_int_specifier(t_type type, LL_int num);
int				ft_unsig_int_specifier(t_type type, ULL_int num);
int				ft_atoi(const char *s);
int				ft_skip_size(int size);
int				ft_zero_skip(const char *format);
int				ft_parse_type(const char *format, t_type *type);
void			error(int x, va_list vl);
int				print_n_char(int num, char c);
int				ft_unsig_specifier(t_type type, ULL_int elem);
int				ft_print_unsig(t_type type, ULL_int elem);

void	test_unsig_int_arg1(ULL_int num);
void	test_unsig_int_arg2(ULL_int num);
void	test_int_arg1(int64_t num);
void	test_int_arg2(int64_t num);
int		ft_printf(const char *format, ...);

#endif
