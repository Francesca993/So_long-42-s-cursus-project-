# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fmontini <fmontini@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/12 11:55:52 by fmontini          #+#    #+#              #
#    Updated: 2025/02/28 17:11:07 by fmontini         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Executable name
NAME	=	so_long

# Source files (add your files from src/ here)
SRC	=	so_long.c \
		ft_to_allocate_map.c \
		ft_to_copy_map_from_fd.c \
		ft_validatemap_utils.c \
		ft_for_flood_fill.c \
		ft_to_validate_map.c \
		ft_open_image.c \
		mlx_init.c \
		ft_to_exit.c \
		ft_hook.c \
		ft_for_bonus.c \

# adds the src/ prefix to files in SRC
SRC	:= $(addprefix src/, $(SRC))

# .c to .o compilation
OBJ	=	$(SRC:.c=.o)

# compilation flags
CFLAGS	=  -Wall -Werror -Wextra -g -gdwarf-4 -O0 -I./include -Imlx

# MLX flags
MLX_DIR = minilibx
MINILIBX_FLAGS	=  -I $(MLX_DIR) -L $(MLX_DIR) -lmlx -lXext -lX11 -lm -lbsd

# Libft
LIBFT_DIR = Libft
LIBFT = $(LIBFT_DIR)/libft.a

# Printf
FT_PRINTF_DIR = Printf
FT_PRINTF = $(FT_PRINTF_DIR)/ft_printf.a

# Rules
$(NAME): $(OBJ) $(LIBFT) $(GNL_LIB) $(FT_PRINTF)
	@make -C $(MLX_DIR)
	@make -C $(LIBFT_DIR)
	@make -C $(FT_PRINTF_DIR)
	cc -o $(NAME) $(OBJ) $(LIBFT) $(GNL_LIB) $(CFLAGS) $(MINILIBX_FLAGS) $(FT_PRINTF)

# Esegui il Makefile di libft
$(LIBFT):
	@make -C $(LIBFT_DIR)
# Esegui Makefile di ft_printf
$(FT_PRINTF):
	@make -C $(FT_PRINTF_DIR)

all:	$(NAME)

clean:
	rm -rf $(OBJ)
	@make clean -C $(LIBFT_DIR)
	@make clean -C $(FT_PRINTF_DIR)

fclean:	clean
	rm -rf $(NAME)
	@make fclean -C $(LIBFT_DIR)
	@make fclean -C $(FT_PRINTF_DIR)

re:	fclean all 
	@make re -C $(LIBFT_DIR)
	@make re -C $(FT_PRINTF_DIR)

.PHONY : all clean fclean re
