NAME	=	so_long

#SRCS	=	$(wildcard src/*.c)
SRCS	=	src/so_long.c			\
			src/sl_parser_check.c	\
			src/sl_parser_init.c	\
			src/sl_parser_error.c	\
			src/sl_move_player.c	\
			src/sl_move_left_right.c \
			src/sl_move_up_down.c	\
#SRCS	=	so_long.c	so_long_check.c	so_long_utils.c
#DIR		=	src/
SRCS_B	=	src_bonus/so_long_bonus.c			\
			src_bonus/sl_parser_check_bonus.c	\
			src_bonus/sl_parser_init_bonus.c	\
			src_bonus/sl_parser_error_bonus.c	\
			src_bonus/sl_move_player_bonus.c	\
			src_bonus/sl_move_left_right_bonus.c \
			src_bonus/sl_move_up_down_bonus.c	\
			src_bonus/sl_move_enemy.c			\

OBJ		=	$(SRCS:%.c=%.o)

OBJ_B		=	$(SRCS_B:%.c=%.o)

LIB		=	libft/libft.a

INCLUDE	=	include/

HEADER	=	so_long.h

CC		=	gcc

FLAGS	=	-Wall -Wextra -Werror

RM		= rm -rf

MLX 	= -framework OpenGL -framework AppKit -lmlx
#---------------------------------------------------------------------------------
RED		=	\033[1;31m
BLUE	=	\033[1;34m
YELLOW	=	\033[1;33m
WHITE	=	\033[1;32m
PUPURE	=	\033[1;35m
GRY		=	\033[1;30m
TURQUOISE =	\033[36;1m
END		=	\033[0m
#---------------------------------------------------------------------------------
.PHONY:		all	clean	fclean	re	bonus	libft

all:		libft $(NAME)

libft:
			@$(MAKE) -C libft/

$(NAME):	$(OBJ)
			$(CC) $(FLAGS) $(OBJ) $(LIB) $(MLX) -o $(NAME)
			@echo "$(TURQUOISE)\n< Complited $(NAME) >\n$(END)"

%.o :		%.c $(INCLUDE)$(HEADER)
			$(CC) $(FLAGS)  -c $< -o $@ -I $(INCLUDE)

bonus:		libft $(OBJ_B)
			$(CC) $(FLAGS) $(OBJ_B) $(LIB) $(MLX) -o $(NAME)
			@echo "$(TURQUOISE)\n< Complited $(NAME) >\n$(END)"

clean:
			@$(RM) $(OBJ) $(OBJ_B)
			@$(MAKE) -C libft/ clean
			@echo "$(YELLOW)\n< Cleaning succeed >\n$(END)"

fclean:		clean
			@$(MAKE) -C libft/ fclean
			@$(RM) $(NAME)
			@echo "$(YELLOW)\n< All created files were deleted >\n$(END)"

re:			fclean all
			@echo "$(BLUE)\n< Remake done >\n$(END)"


