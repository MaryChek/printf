NAME = libftprintf.a

LIBFTA = libft.a

SRCS = ft_print_float.c ft_printf.c long_arithmetic.c print_format.c ft_skip.c ft_parse.c ft_print_int.c ft_print_unsig_int.c print_function.c

OBJ = $(SRCS:.c=.o)

LIBDIR = libft/

LIBNAME = libft/libft.a

#CFLAGS = -Wall -Wextra -Werror$(CFLAGS)

all: $(NAME)

%.o: %.c
	gcc  -c $< -o $@

$(NAME): $(OBJ)
	@make -C $(LIBDIR)
	@cp libft/libft.a ./$(NAME)
	ar rc $(NAME) $(OBJ)

clean:
	@/bin/rm -f $(OBJ)
	@make -C $(LIBDIR) clean
	@echo OBJECTS FILES HAS BEEN DELETED.

test:
	gcc ft_print_float.c ft_printf.c long_arithmetic.c print_format.c ft_skip.c ft_parse.c ft_print_int.c ft_print_unsig_int.c print_function.c -L libft -lft -g

fclean: clean
	@/bin/rm -f $(NAME)
	@make -C $(LIBDIR) fclean
	@echo OBJECT FILES AND EXECUTABLE HAS BEEN DELETED.

re: fclean all
