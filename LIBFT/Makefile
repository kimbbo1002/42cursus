CC = cc 
CFLAGS = -Wall -Werror -Wextra
SRCS = 
OBJS = ${SRCS:.c=.o}
NAME = libft.a

all:
	${NAME}

${NAME}: ${OBJS}
	ar rcs $@ $^

${OBJS}: %.o: %.c 
	${CC} -c ${CFLAGS} $^-o $@

clean:
	rm -f ${OBJS}

fclean:
	rm -f ${NAME}

re:
	fclean all