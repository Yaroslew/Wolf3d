NAME = wolf3d
LIB = libft/libftprintf.a
MLX = libft/libmlx.a
INCL = fdfHeader.h
FLAGS = #-Wall -Wextra -Werror
SRC =   ./src/main.c\
		./src/mess_err.c\
		./src/check.c\
		./src/init.c\
		./src/record_map.c\


OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(LIB)
	@gcc $(SRC) $(LIB) $(MLX) -lmlx -framework OpenGL -framework AppKit -o $@

$(LIB):
	@make -C libft

$(OBJ): %.o: %.c
	gcc $(FLAGS) -c $< -I $(INCL) -o $@

clean:
	@make clean -C libft
	@rm -f $(OBJ)

fclean: clean
	@make fclean -C libft
	@rm -f $(NAME)

re: fclean all