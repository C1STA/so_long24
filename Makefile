RED		=\033[0;31m
CYAN	=\033[0;36m
GREEN	=\033[0;32m
YELLOW	=\033[0;33m
WHITE	=\033[0;37m

NAME	= so_long
CC		= cc
CFLAGS	= -Wall -Wextra -Werror
INC		= -I inc/ -I lib/libft/ -I lib/minilibx-linux/
LIBFT	= -L lib/libft -lft
LIBX	=	-L lib/minilibx-linux -lmlx_Linux
LIBXFLAGS	=	-lmlx -lXext -lX11
RM		= rm -rf

SRCPATH	= src/
SRC	=	main.c \
			map_extension.c \
			error.c \
			isvalid.c \
			isplayable.c \
			launcher.c \
			moves.c

all: $(NAME)

OBJDIR	= .config/obj/
OBJ		= $(addprefix $(OBJDIR), $(SRC:.c=.o))

DEPDIR	= .config/dep/
DEP		= $(addprefix $(DEPDIR), $(SRC:.c=.d))

$(NAME): $(OBJ)
		@echo "$(CYAN)Linking $(NAME)...$(WHITE)"
		@$(MAKE) --no-print-directory -C lib/libft
		@$(MAKE) --no-print-directory -C lib/minilibx-linux
		@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(LIBX) $(LIBXFLAGS) -o $(NAME)
		@echo "$(GREEN)Done$(WHITE)"

$(OBJDIR)%.o: $(SRCPATH)%.c
		@mkdir -p $(@D)
		@$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(DEPDIR)%.d: $(SRCPATH)%.c
		@mkdir -p $(@D)
		@$(CC) $(CFLAGS) $(INC) -MM $< -MT $(@:.d=.o) -MF $@ -MP

-include $(DEP)

clean:
		@echo "$(RED)Cleaning $(NAME)...$(WHITE)"
		@$(MAKE) --no-print-directory fclean -C lib/libft
		@$(MAKE) --no-print-directory clean -C lib/minilibx-linux
		@$(RM) .config
		@echo "$(GREEN)Done$(WHITE)"

fclean: clean
		@$(RM) $(NAME)

re: fclean all

norm:
	@echo "$(YELLOW)Executing norminette...$(WHITE)"
	@norminette src/ inc/ lib/libft

.PHONY: all clean fclean re norm