NAME = wolf3d
LIB = libft/libftprintf.a
#MLX = libft/libmlx.a

SDLHEAD = -I /Users/pcorlys-/Library/Frameworks/SDL2.framework/Headers
SDLFRAME = -F /Users/pcorlys-/Library/Frameworks/ -framework SDL2

INCL = wolf.h
FLAGS = #-Wall -Wextra -Werror
FLAGSSDL = -framework OpenGL -framework AppKit
SRC =   ./src/main.c\
 		./src/mess_err.c\
 		./src/check.c\
 		./src/init.c\
 		./src/record_map.c\
 		./src/ray_casting.c\
 		./src/draw.c\
 		./src/sdl_action.c\


OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(LIB)
	@gcc $(SRC) $(LIB) $(SDLHEAD) $(SDLFRAME) $(FLAGS) $(FLAGSSDL) -o $@

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