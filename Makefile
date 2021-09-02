PUSH_NAME		= push_swap
FLAGS 			= -Wall -Wextra -Werror
INC				= -I includes

PUSH_SRC_NAME 	= push_swap.c parse.c operations.c \
				operations2.c command.c sort.c fills_value.c \
				find_min_value.c command_exec.c sort_help.c \
				sort_small.c

PUSH_OBJ_NAME 	= $(PUSH_SRC_NAME:.c=.o)
PUSH_OBJ 		= $(addprefix $(OBJ_DIR),$(PUSH_OBJ_NAME))

LIB_DIR 		= libft/
SRC_DIR 		= src/
OBJ_DIR 		= obj/

all:			$(PUSH_NAME)

$(PUSH_NAME):	$(PUSH_OBJ)
	@make -C $(LIB_DIR) --silent
	@gcc -o $(PUSH_NAME) $(PUSH_OBJ) -L $(LIB_DIR) -lft
	@echo "##### push_swap compiling finished! #####"

$(OBJ_DIR)%.o:	$(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@echo "##### Creating" [ $@ ] " #####"
	@gcc $(FLAGS) -o $@ -c $< $(INC)

clean:
	@make -C $(LIB_DIR) clean  --silent
	@rm -f $(PUSH_OBJ)
	@echo "##### Removed object files #####"

fclean:			clean
	@make -C $(LIB_DIR) fclean  --silent
	@rm -f $(PUSH_NAME)
	@echo "##### Removed binary files #####"

re:				fclean all

.PHONY:			all clean fclean re