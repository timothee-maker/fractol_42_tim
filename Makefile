NAME = fractol
CC = cc
FOLDER = srcs
LIBFT = /libft
MLX = /mlx_linux
FLAGS = -Wall -Wextra -Werror
SRC = $(addprefix $(FOLDER)/, test.c circle.c)
INCLUDE =-I./include
INCLUDE_MLX = -I./mlx_linux
INCLUDE_LIBFT = -I./libft
OBJ = $(SRC:.c=.o)
OBJ_DIR = obj

all : $(NAME)

obj :
	mkdir -p $(OBJ_DIR)
	mkdir -p $(OBJ_DIR)/fractol_obj

%(FOLDER)/%.o : $(FOLDER)/%.c
	@$(CC) -c $< -o $@
#$(INCLUDE_LIBFT) $(INCLUDE_MLX) $(INCLUDE) 
$(NAME) : $(OBJ) $(LIBFT) $(MLX)
	@$(CC) $(OBJ) -L.$(LIBFT) -lft -L.$(MLX) -lmlx -lXext -lX11 -lm -o $(NAME)

$(LIBFT) :
	@make re -C libft
	@echo 'libft done tulululu'

$(MLX) :
	@make -C mlx_linux
	@echo 'mlx done palala'

clean :
	@rm -rf $(OBJ)
	@rm -rf $(OBJ_DIR)
	@make clean -C libft

fclean : clean
	@rm -rf $(NAME)
	@make fclean -C libft
	@make clean -C mlx_linux

re : fclean all

.PHONY : all clean fclean re
