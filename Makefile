NAME	=	so_long

#SRCS	=	$(wildcard src/*.c)
SRCS	=	src/so_long.c	src/so_long_check.c	src/so_long_utils.c

OBJ		=	$(SRCS:%.c=%.o)

LIB		=	libft/libft.a

INCLUDE	=	include/

HEADER	=	so_long.h

СС		=	gcc

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
			$(CC) $(FLAGS) $(OBJ) $(LIB) -o $(NAME)
			@echo "$(TURQUOISE)\n< Complited $(NAME) >\n$(END)"

%.o 	:	%.c $(INCLUDE)$(HEADER)
			$(CC) $(FLAGS)  -c $< -o $@ -I $(INCLUDE)

clean:
			@$(RM) $(OBJ)
			@$(MAKE) -C libft/ clean
			@echo "$(YELLOW)\n< Cleaning succeed >\n$(END)"

fclean:		clean
			@$(MAKE) -C libft/ fclean
			@$(RM) $(NAME)
			@echo "$(YELLOW)\n< All created files were deleted >\n$(END)"

re:			fclean all
			@echo "$(YELLOW)\n< Remake done >\n$(END)"


