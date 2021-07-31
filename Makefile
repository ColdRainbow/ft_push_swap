.PHONY: all push_swap checker clean fclean re

NAME_1 = "push_swap"
NAME_2 = "checker"

CC = clang
CCFLAGS = -Wall -Wextra -Werror

H_1 = include/push_swap.h
H_2 = include/checker.h

DIR_SRC_1 = src_push_swap/
SRC_1 =	main.c \
		parser.c \
		extra_1.c \
		extra_2.c \
		sort_recursive_1.c \
		sort_recursive_2.c \
		sort_recursive_utils.c \
		sort_simple_1.c \
		sort_simple_utils.c \
		sort_utils.c \
		sort_utils_2.c \
		stack_manage_1.c \
		stack_manage_2.c \
		stack_manage_3.c \
		lib_1.c \
		lib_2.c \
		lib_3.c
SRC_1 := $(addprefix $(DIR_SRC_1), $(SRC_1))

DIR_SRC_2 = src_checker/
SRC_2 =	main.c \
		extra_1.c \
		extra_2.c \
		lib_1.c \
		lib_2.c \
		lib_3.c \
		lib_4.c \
		lib_5.c \
		parser.c \
		stack_manage_1.c \
		stack_manage_2.c \
		stack_manage_3.c
SRC_2 := $(addprefix $(DIR_SRC_2), $(SRC_2))

DIR_OBJ_1 := obj_1/
OBJ_1 = $(SRC_1:%.c=%.o)
OBJ_1 := $(patsubst $(DIR_SRC_1)%, $(DIR_OBJ_1)%, $(OBJ_1))

DIR_OBJ_2 := obj_2/
OBJ_2 = $(SRC_2:%.c=%.o)
OBJ_2 := $(patsubst $(DIR_SRC_2)%, $(DIR_OBJ_2)%, $(OBJ_2))

all: push_swap checker

push_swap: $(DIR_OBJ_1) $(NAME_1)

checker: $(DIR_OBJ_2) $(NAME_2)

$(DIR_OBJ_1):
	@mkdir -p $(DIR_OBJ_1)

$(DIR_OBJ_2):
	@mkdir -p $(DIR_OBJ_2)

$(NAME_1): $(OBJ_1)
	@$(CC) $(CCFLAGS) $(OBJ_1) -o $(NAME_1)
	@echo "--------------------------------"
	@echo "${NAME_1} compiled"
	@echo "--------------------------------"

$(NAME_2): $(OBJ_2)
	@$(CC) $(CCFLAGS) $(OBJ_2) -o $(NAME_2)
	@echo "--------------------------------"
	@echo "${NAME_2} compiled"
	@echo "--------------------------------"

$(DIR_OBJ_1)%.o: $(DIR_SRC_1)%.c $(H_1) Makefile
	@echo $<
	@$(CC) $(CCFLAGS) -c $< -o $@

$(DIR_OBJ_2)%.o: $(DIR_SRC_2)%.c $(H_2) Makefile
	@echo $<
	@$(CC) $(CCFLAGS) -c $< -o $@

clean:
	@rm -rf $(DIR_OBJ_1)
	@rm -rf $(DIR_OBJ_2)

fclean: clean
	@rm -rf $(NAME_1)
	@rm -rf $(NAME_2)

re: fclean all