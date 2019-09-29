TARGET		= wolf3d
OS			= $(shell uname)

# Directories
SRCS_DIR	= ./src
OBJS_DIR	= ./obj
FT_DIR		= ./libft

# Sources
SRC_FILES	=   main.c\
                check.c\
                clear.c\
                draw.c\
                init.c\
                mess_err.c\
                move.c\
                ray_casting.c\
                record_map.c\
                sdl_action.c\

SRCS 		= $(addprefix $(SRCS_DIR)/, $(SRC_FILES))
OBJS		= $(addprefix $(OBJS_DIR)/, $(SRC_FILES:c=o))


# Includes
INCL		= -I ./includes
FT_INCL		= -I ./libft/includes
LIBSINC		= -I ~/.brew/include

# Libraries
FT_LIB		= $(FT_DIR)/libftprintf.a
LIBS_LINK	= -L $(FT_DIR) -L ~/.brew/lib -rpath ~/.brew/lib -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer -lpthread -lm



# Compilation
COMPILER	= gcc
BUILD_FLAGS = #-Wall -Wextra -Werror
DEBUG_FLAGS = $(BUILD_FLAGS) -g
O_FLAGS		= -Ofast


.PHONY: all clean fclean re

all: $(TARGET)

$(TARGET): $(which brew) $(FT_LIB) $(OBJS)
	@$(COMPILER) $(OBJS) $(FT_LIB) $(LIBS_LINK) -o $(TARGET)
	@echo Relinking

$(FT_LIB):
	@echo "Installing sld2 libs"
	@brew install SDL2 > /dev/null 2>&1 || true
	@brew install SDL2_image > /dev/null 2>&1 || true
	@brew install SDL2_ttf > /dev/null 2>&1 || true
	@brew install SDL2_mixer > /dev/null 2>&1 || true
	@make -C $(FT_DIR) > /dev/null
	@mkdir -p $(OBJS_DIR)


$(which brew):
	@echo "Brew not found, installing brew"
	@chmod +x ./install.sh && ./install.sh > /dev/null 2>&1

$(OBJS_DIR)/%.o:$(SRCS_DIR)/%.c
	@$(COMPILER) $(DEBUG_FLAGS) $(O_FLAGS) $(FT_INCL) $(LIBSINC) $(INCL) -o $@ -c $<
	@echo Recompiling $<

clean:
	@rm -rf $(OBJS_DIR) > /dev/null
	@make -C $(FT_DIR) clean > /dev/null

fclean: clean
	@rm -rf $(TARGET) > /dev/null
	@make -C $(FT_DIR) fclean > /dev/null

re: fclean all
