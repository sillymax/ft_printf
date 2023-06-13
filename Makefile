SRCS	=	ft_printf.c \
			print_char.c \
			print_str.c \
			print_dec.c \
			print_uint.c \
			print_low_hex.c \
			print_upp_hex.c \
			print_ptr.c \
			print_percent.c \
			int_format.c \
			functions.c \

LIBFT_PATH	=	libft/ft_atoi.c \
				libft/ft_strlen.c \

NAME	=	libftprintf.a
OBJS	=	$(SRCS:.c=.o)
LOBJS	= 	$(LIBFT_PATH:.c=.o)
GCC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror
RM		=	rm -f
AR		=	ar -rcs

all: $(NAME)

$(NAME): $(OBJS) $(LOBJS)
	$(AR) $(NAME) $(OBJS) $(LOBJS)

bonus: all

clean:
	$(RM) $(OBJS) $(LOBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re