NAME = wolf3d
SRC = ./src
OBJ = ./obj
LIB = ./libft

SRC_FILES = main.c\
            check.c\
            clear.c\
            draw.c\
            init.c\
            mess_err.c\
            move.c\
            ray_casting.c\
            record_map.c\
            sdl_action.c\
            utils.c\

SRCS 		= $(addprefix $(SRC)/, $(SRC_FILES))
OBJS		= $(addprefix $(OBJ)/, $(SRC_FILES:c=o))

INC_WOLF = -I ./includes
INC_LIB = -I ./libft/includes
INC_BREW = -I ~/.brew/include

LIB_NAME = ./libft/libftprintf.a
LIBS_LINK = -L $(LIB) -L ~/.brew/lib -rpath ~/.brew/lib -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer -lpthread -lm

FLAGS = -Wall -Wextra -Werror -Ofast

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(install_brew) $(LIB_NAME) $(OBJS)
	@gcc $(OBJS) -g $(LIB_NAME) $(LIBS_LINK) -o $(NAME)
	@echo Relinking

$(LIB_NAME):
	@brew install SDL2 > /dev/null 2>&1 || true
	@brew install SDL2_image > /dev/null 2>&1 || true
	@brew install SDL2_ttf > /dev/null 2>&1 || true
	@brew install SDL2_mixer > /dev/null 2>&1 || true
	@make -C $(LIB) > /dev/null
	@mkdir -p $(OBJ)


$(install_brew):
	echo "installing brew"
	@chmod +x ./install.sh && ./install.sh > /dev/null 2>&1

$(OBJ)/%.o:$(SRC)/%.c
	@gcc -g $(FLAGS) $(INC_LIB) $(INC_BREW) $(INC_WOLF) -o $@ -c $<

clean:
	@rm -rf $(OBJ) > /dev/null
	@make -C $(LIB) clean > /dev/null

fclean: clean
	@rm -rf $(NAME) > /dev/null
	@make -C $(LIB) fclean > /dev/null

re: fclean all
