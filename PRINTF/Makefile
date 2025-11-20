NAME = libftprintf.a
CC = cc 
CFLAGS = -Wall -Wextra -Werror
INCL = ft_printf.h
SRCS = ft_printf.c \
		ft_putchar.c \
		ft_putstr.c \
		ft_putnbr.c \
		ft_putunbr.c \
		ft_puthex.c \
		ft_putvoid.c \
		ft_strlen.c \
		ft_intlen.c \
		ft_uintlen.c
OBJS = ${SRCS:.c=.o}

all: ${NAME}

${NAME}: ${OBJS}
	ar rcs $@ $^

%.o: %.c
	${CC} ${CFLAGS} -c $^ -o $@

clean:
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re
