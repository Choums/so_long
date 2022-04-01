NAME    = so_long
OS        = $(shell uname)

# directories
SRCDIR			= ./srcs
INCDIR			= ./includes
OBJDIR			= obj

# src / obj files
SRC			= 	map_checker.c\
				so_long.c\
				so_long_utils.c\
				window_management.c\
				mouvement.c\
				get_next_line.c\
				get_next_line_utils.c


OBJ				= $(addprefix $(OBJDIR)/,$(SRC:.c=.o))

# compiler
CC				= gcc
CFLAGS			= -Wall -Wextra -Werror -g

# mlx library
ifeq ($(OS), Linux)
    MLX        = ./miniLibX_X11/
    MLX_LNK    = -L $(MLX) -l mlx -lXext -lX11
else
    MLX        = ./miniLibX/
    MLX_LNK    = -L -l mlx -framework OpenGL -framework AppKit
endif

MLX_INC		= -I $(MLX)
MLX_LIB		= $(addprefix $(MLX),mlx.a)

# ft library
FT			=	./libft/
FT_LIB		=	$(addprefix $(FT),libft.a)
FT_INC		=	-I ./libft
FT_LNK		=	-L ./libft -l ft -l pthread

all:			obj $(FT_LIB) $(NAME)

obj:
				mkdir -p $(OBJDIR)

$(OBJDIR)/%.o:	$(SRCDIR)/%.c
				$(CC) $(CFLAGS) -Imlx $(FT_INC) -I $(INCDIR) -o $@ -c $<

$(FT_LIB):
				@make -C $(FT)

$(MLX_LIB):
				@make -C $(MLX)

$(NAME):		$(OBJ)
				$(CC) $(CFLAGS) $(OBJ) -lmlx -framework OpenGL -framework AppKit $(FT_LNK) -lm -o $(NAME)

clean:
				rm -rf $(OBJDIR)
				make -C $(FT) clean

fclean:			clean
				rm -rf $(NAME)
				make -C $(FT) fclean

re: fclean all