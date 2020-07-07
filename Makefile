NAME = libftprintf.a

LIBFTA = libft.a

SRC_DIR =	srcs/

OBJ_DIR =	obj/

SRCS = ft_round_a_num.c help_func_for_parse.c \
	work_with_the_type_struct.c ft_print_float.c \
	ft_printf.c long_arithmetic.c print_format.c \
	ft_skip.c ft_parse.c ft_print_int.c \
	ft_print_unsig_int.c print_function.c \
	parse_bonus_part.c print_float_arrays.c

OBJ = $(SRCS:.c=.o)

OBJ =	$(addprefix $(OBJ_DIR), $(OBJ))

LIBDIR = libft/

LIBNAME = libft/libft.a

CFLAGS = -Wall -Wextra -Werror$(CFLAGS)

all: $(OBJ_DIR) $(NAME)

%.o: %.c
	gcc  -c $< -o $@

$(OBJ_DIR):
		@mkdir -p $(OBJ_DIR)

$(NAME): $(OBJ) 
	@make -C $(LIBDIR)
	@cp libft/libft.a ./$(NAME)
	ar rc $(NAME) $(addprefix $(OBJ_DIR),$(OBJ))

clean:
	@/bin/rm -f $(OBJ_DIR)
	@make -C $(LIBDIR) clean
	@echo OBJECTS FILES HAS BEEN DELETED.

fclean: clean
	@/bin/rm -f $(NAME)
	@make -C $(LIBDIR) fclean
	@echo OBJECT FILES AND EXECUTABLE HAS BEEN DELETED.

re: fclean all
