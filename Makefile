SRCS		=	srcs/so_long.c srcs/so_long_utils.c srcs/window_management.c

OBJS		=	${SRCS:.c=.o}

NAME		=	so_long

CC			=	clang

CFLAGS		=	#-Wall -Wextra -Werror

.c.o:			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

%.o: 			%.c
				$(CC) ${CFLAGS} -Imlx -c $< -o $@

RM			=	rm -f

FRAME		=	-Lmlx -lmlx -framework OpenGL -framework AppKit

${NAME}:		${OBJS}
				${CC} ${CFLAGS} ${FRAME} ${OBJS} -o ${NAME}

all:			${NAME}

clean:
				${RM} ${OBJS}
				${MAKE} clean -C ./libft

fclean:			clean
				${RM} ${NAME}
				${MAKE} fclean -C ./libft

re:				fclean all

.PHONY:			all clean fclean re
