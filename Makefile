SRCS		=	srcs/so_long.c\
				srcs/so_long_utils.c\
				srcs/window_management.c\
				srcs/map_checker.c\
				srcs/get_next_line/get_next_line.c\
				srcs/get_next_line/get_next_line_utils.c

OBJS		=	${SRCS:.c=.o}

NAME		=	so_long

LIB			=	./libft/libft.a

CC			=	clang

CFLAGS		=	-fsanitize=address -g #-Wall -Wextra -Werror

.c.o:			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

%.o: 			%.c
				$(CC) ${CFLAGS} -I/usr/include -Imlx_linux -O3 -c $< -o $@

RM			=	rm -f

FRAME		=	-lmlx -framework OpenGL -framework AppKit

${NAME}:		${OBJS}
				${MAKE} -C ./libft
				$(CC) $(OBJ) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

all:			${NAME}

clean:
				${RM} ${OBJS}
				${MAKE} clean -C ./libft

fclean:			clean
				${RM} ${NAME}
				${MAKE} fclean -C ./libft

re:				fclean all

.PHONY:			all clean fclean re
