NAME    = so_long

SRCDIR			= ./srcs
INCDIR			= ./includes
OBJDIR			= obj

SRC			= 	map_checker.c\
				so_long.c\
				so_long_utils.c\
				window_management.c\
				mouvement.c\
				get_next_line.c\
				get_next_line_utils.c


OBJ				= $(addprefix $(OBJDIR)/,$(SRC:.c=.o))

CC				= gcc
CFLAGS			= -Wall -Wextra -Werror -g

FT			=	./libft/
FT_LIB		=	$(addprefix $(FT),libft.a)
FT_INC		=	-I ./libft

all:			obj $(FT_LIB) $(NAME)

obj:
				mkdir -p $(OBJDIR)

$(OBJDIR)/%.o:	$(SRCDIR)/%.c
				$(CC) $(CFLAGS) -Imlx $(FT_INC) -I $(INCDIR) -o $@ -c $<

$(FT_LIB):
				make -C $(FT)

$(NAME):		$(OBJ)
				$(CC) $(CFLAGS) $(OBJ) -lmlx -framework OpenGL -framework AppKit $(FT_LIB) -lm -o $(NAME)

clean:
				rm -rf $(OBJDIR)
				make -C $(FT) clean

fclean:			clean
				rm -rf $(NAME)
				make -C $(FT) fclean

re: fclean all