# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fmontini <fmontini@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/12 11:55:52 by fmontini          #+#    #+#              #
#    Updated: 2025/02/13 15:30:47 by fmontini         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Executable name
NAME	=	so_long

# Source files (add your files from src/ here)
SRC	=	main.c

# adds the src/ prefix to files in SRC
SRC	:= $(addprefix src/, $(SRC))

# .c to .o compilation
OBJ	=	$(SRC:.c=.o)

# compilation flags
CFLAGS	=	-Wall -Werror -Wextra -I./include -Imlx

# MLX flags
MLX_DIR = mlx
MINILIBX_FLAGS	=  -I $(MLX_DIR) -L $(MLX_DIR) -lmlx -lXext -lX11 -lm -lbsd

# Rules (no relink)
$(NAME):	$(OBJ) $(OBJ_MAIN)
	make -C ./mlx
	cc -o $(NAME) $(OBJ) $(CFLAGS) $(MINILIBX_FLAGS)

all:	$(NAME)

clean:
	rm -rf $(OBJ)

fclean:	clean
	rm -rf $(NAME)

re:	fclean all

.PHONY : all clean fclean re
