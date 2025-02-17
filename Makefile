# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fmontini <fmontini@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/12 11:55:52 by fmontini          #+#    #+#              #
#    Updated: 2025/02/17 13:11:15 by fmontini         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Executable name
NAME	=	so_long

# Source files (add your files from src/ here)
SRC	=	so_long.c \
		so_long_map_utils.c

# adds the src/ prefix to files in SRC
SRC	:= $(addprefix src/, $(SRC))

# .c to .o compilation
OBJ	=	$(SRC:.c=.o)

# compilation flags
CFLAGS	=	-Wall -Werror -Wextra -I./include -Imlx

# MLX flags
MLX_DIR = minilibx
MINILIBX_FLAGS	=  -I $(MLX_DIR) -L $(MLX_DIR) -lmlx -lXext -lX11 -lm -lbsd

# Libft
LIBFT_DIR = Libft
LIBFT = $(LIBFT_DIR)/libft.a

# Get Next Line
GNL_DIR = Get_next_line
GNL_LIB = $(GNL_DIR)/get_next_line.a

# Rules
$(NAME): $(OBJ) $(LIBFT) $(GNL_LIB)
	@make -C $(MLX_DIR)
	@make -C $(LIBFT_DIR)
	@make -C $(GNL_DIR)
	cc -o $(NAME) $(OBJ) $(LIBFT) $(GNL_LIB) $(CFLAGS) $(MINILIBX_FLAGS)

# Esegui il Makefile di libft
$(LIBFT):
	@make -C $(LIBFT_DIR)

# Esegui il Makefile di get_next_line
$(GNL_LIB):
	@make -C $(GNL_DIR)

all:	$(NAME)

clean:
	rm -rf $(OBJ)

fclean:	clean
	rm -rf $(NAME)

re:	fclean all

.PHONY : all clean fclean re
