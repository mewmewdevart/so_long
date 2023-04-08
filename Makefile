# The name of the executable
NAME = so_long
# Path to the directory where the executable will be stored
BINS_PATH = ./bin/
NAME = ${BINS_PATH}so_long

# Compilation flags
CC = cc
CFLAGS = -Wall -Wextra -Werror -g3
# Linker flags : 'libft', 'mlx' and 'mlx' for Linux, 'lib' for X Window System, 'xext' for a single extension, and 'lm' for the math library
LFLAGS = -lft -lmlx -lmlx_Linux -lX11 -lXext -lm

# Command to remove files/directories
REMOVE = rm -rf
# Command to create directories
MKDIR = mkdir -p

# Path variables
SRCS_PATH =  ./srcs/
OBJS_PATH = ./objs/
LIBS_PATH = ./libs/
BINS_PATH = ./bin/
HEADER_PATH = ./include/

# Path to libraries
LIBFT_PATH = $(LIBS_PATH)libft/
MLX_PATH = $(LIBS_PATH)mlx/

# Source files
SRCS_FILES = map_validate.c \
	map_init.c \
	utils.c \
	errors.c \
	frees.c \
	game_init.c \
	game_events.c \
	draw.c \
	exit_actions.c \

# The full path to source file
SOURCES = $(addprefix $(SRCS_PATH), $(SRCS_FILES))
# Object files
OBJS_FILES = $(patsubst %.c, $(OBJS_PATH)%.o, $(SRCS_FILES))
OBJECTS = $(addprefix $(OBJS_PATH), $(OBJS_FILES))

# Compiler flags to include library headers
INCLUDES = -I $(LIBFT_PATH) -I $(MLX_PATH)
# Compiler flags to link to libraries
PATH_LIBS = -L$(LIBFT_PATH) -L$(MLX_PATH)

# Color codes for terminal output
DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

# The default target calling for the executable
all : $(NAME)

# Target for cloning the minilibx library into libs/ folder
call_mlx:
	@read -p "Clone via SSH (s) or HTTP (h)? " clone_method; \
	if [ $$clone_method = "s" ]; then \
		echo "$(GREEN)Cloning 'mlx' via SSH into 'libs/mlx'...$(DEF_COLOR)"; \
		git clone git@github.com:42Paris/minilibx-linux.git libs/mlx; \
	elif [ $$clone_method = "h" ]; then \
		echo "$(GREEN)Cloning 'mlx' via HTTP into 'libs/mlx'...$(DEF_COLOR)"; \
		git clone https://github.com/42Paris/minilibx-linux libs/mlx; \
	else \
		echo "$(RED)Invalid option. Please enter 's' for SSH or 'h' for HTTP.$(DEF_COLOR)"; \
		exit 1; \
	fi

# The target to build the executable
$(NAME) : $(OBJS_FILES)
	$(MKDIR) $(BINS_PATH)
	make -C $(LIBFT_PATH) --no-print-directory
	make -C $(MLX_PATH) --no-print-directory
	$(CC) $(CFLAGS) $(OBJS_FILES) -o $(NAME) $(SRCS_PATH)main.c $(PATH_LIBS) $(LFLAGS)
	@echo "$(GREEN)______________	  ___   _____________________"
	@echo "$(GREEN)7     77     7	  7  7   7     77     77     7"
	@echo "$(GREEN)|  ___!|  7  |	  |  |   |  7  ||  _  ||   __!"
	@echo "$(GREEN)!__   7|  |  |	  |  !___|  |  ||  7  ||  !  7"
	@echo "$(GREEN)7     ||  !  |____|     7|  !  ||  |  ||     |"
	@echo "$(GREEN)!_____!!_____!____!_____!!_____!!__!__!!_____!"
	@echo "$(GREEN)◞( ､ᐛ)､＿/ The Makefile of [SO_LONG] has been compiled!$(DEF_COLOR)" 

# Compiles C source files into object files
$(OBJS_PATH)%.o : $(SRCS_PATH)%.c
	$(MKDIR) $(OBJS_PATH)
	$(CC) $(CFLAGS) -I $(HEADER_PATH) -c $< -o $@

# Cleans object files and dependencies
clean :
	@$(REMOVE) $(OBJS_PATH)
	@make clean -C $(LIBFT_PATH) --no-print-directory
	@make clean -C $(MLX_PATH) --no-print-directory
	@echo "$(BLUE)[SO_LONG] Object files cleaned!$(DEF_COLOR)"

# Cleans everything generated by the Makefile
fclean : clean
	@$(REMOVE) $(NAME) $(BINS_PATH) $(OBJS_PATH)
	@make fclean -C $(LIBFT_PATH) --no-print-directory
	@echo "$(BLUE)[SO_LONG] Executable files and directories cleaned!$(DEF_COLOR)"

# Cleans everything generated by the Makefile and rebuild all
re : fclean all

# Phony targets
.PHONY : all clean fclean re make_directory libft mlx
