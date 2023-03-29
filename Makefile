# omg, why it is so long? 
NAME = so_long
LIB_SOLONG = lib_solong.a

# compilation and settings
CC = cc
CFLAGS = -Wall -Wextra -Werror -g3
ICON_GAME = -DICON=\"rscs/sprites/iconGame.xpm\"
LFLAGS = -lft -lmlx -lmlx_Linux -lX11 -lXext -lXext -lm $(ICON_GAME)
AR = ar rcs
REMOVE = rm -rf
MKDIR = mkdir -p

# path variables
SRCS_PATH =  ./srcs/
OBJS_PATH = ./objs/
LIBS_PATH = ./libs/
BINS_PATH = ./bin/
HEADER_PATH = ./include/

# import library
LIBFT_PATH = $(LIBS_PATH)libft/
MLX_PATH = $(LIBS_PATH)mlx/

# sources files
SRCS_FILES = map_validate.c \
	map_init.c \
	utils.c \
	draw.c \
	errors.c \
	frees.c \
	game_init.c \
	player_events.c \
	game_events.c 

SOURCES = $(addprefix $(SRCS_PATH), $(SRCS_FILES))

OBJS_FILES = $(patsubst %.c, %.o, $(SRCS_FILES))
OBJECTS = $(addprefix $(OBJS_PATH), $(OBJS_FILES))

INCLUDES = -I $(LIBFT_PATH) -I $(MLX_PATH)
PATH_LIBS = -L$(LIBFT_PATH) -L$(MLX_PATH)

# colors
DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

# targets
all : make_directory $(NAME)
	@echo "$(GREEN)______________	  ___   _____________________"
	@echo "$(GREEN)7     77     7	  7  7   7     77     77     7"
	@echo "$(GREEN)|  ___!|  7  |	  |  |   |  7  ||  _  ||   __!"
	@echo "$(GREEN)!__   7|  |  |	  |  !___|  |  ||  7  ||  !  7"
	@echo "$(GREEN)7     ||  !  |____|     7|  !  ||  |  ||     |"
	@echo "$(GREEN)!_____!!_____!____!_____!!_____!!__!__!!_____!"
	@echo "$(GREEN)◞( ､ᐛ)､＿/ The Makefile of [SO_LONG] has been compiled!$(DEF_COLOR)" 

make_directory :
	@$(MKDIR) $(BINS_PATH)
	@$(MKDIR) $(OBJS_PATH)

call_mlx :
	@echo "$(GREEN)Cloning 'mlx' into 'libs/mlx'...$(DEF_COLOR)"
	@git clone git@github.com:42Paris/minilibx-linux.git libs/mlx

$(NAME) : $(OBJS_FILES)
	@make -C $(LIBFT_PATH) --no-print-directory
	@make -C $(MLX_PATH) --no-print-directory
	@$(AR) $(LIB_SOLONG) $(OBJS_FILES)
	@$(CC) $(CFLAGS) $(OBJS_FILES) -o $(NAME) $(SRCS_PATH)main.c $(PATH_LIBS) $(LFLAGS)
	@mv $(NAME) $(BINS_PATH)
	@mv $(OBJS_FILES) $(OBJS_PATH)
	@mv $(LIB_SOLONG) $(HEADER_PATH)

$(OBJS_FILES) :
	@$(CC) $(CFLAGS) -I $(HEADER_PATH) -c $(SOURCES)

clean :
	@$(REMOVE) $(OBJS_PATH)
	@make clean -C $(LIBFT_PATH) --no-print-directory
	@make clean -C $(MLX_PATH) --no-print-directory
	@echo "$(BLUE)[SO_LONG] Object files cleaned!$(DEF_COLOR)"

fclean : clean
	@$(REMOVE) $(NAME) $(HEADER_PATH)$(LIB_SOLONG) $(BINS_PATH) $(OBJS_PATH)
	@make fclean -C $(LIBFT_PATH) --no-print-directory
	@echo "$(BLUE)[SO_LONG] Executable files and directories cleaned!$(DEF_COLOR)"

re : fclean all

.PHONY : all clean fclean re make_directory libft so_long mlx
