#!bin/bash

NAME = faneyer.filler

FILES = $(shell ls srcs | grep .c | cut -d "." -f 1)

SRCS = $(addprefix $(PATH_SRCS), $(addsuffix .c, $(FILES)))

PATH_INC = ./includes/

PATH_SRCS = ./srcs/

PATH_OBJ = ./obj/

OBJ = $(addprefix $(PATH_OBJ), $(addsuffix .o, $(FILES)))

INC = $(addprefix $(PATH_INC), filler.h)

FLAGS = -Wall -Wextra -Werror

FL_DEBUG = -g -fsanitize=address

LIGHT_PINK = \033[0;38;5;200m

PINK = \033[0;38;5;198m

DARK_BLUE = \033[0;38;5;110m

GREEN = \033[0;38;5;111m

LIGHT_GREEN = \033[0;38;5;121m

FLASH_GREEN = \033[33;32m

all: $(NAME)

$(NAME): lib $(PATH_OBJ) $(OBJ)
		@echo "$(DARK_BLUE)\nFichiers de "$(NAME)" compilés\n"
		@$(CC) $(FLAGS) -o $(NAME) $(OBJ) ./libft/libft.a
		@echo "$(FLASH_GREEN)Programme "$(NAME)" compilé et prêt à l'usage !\n\033[0m"

$(PATH_OBJ):
		@mkdir obj
		@echo "$(DARK_BLUE) creating object directory"

$(PATH_OBJ)%.o: $(PATH_SRCS)%.c $(INC) libft/libft.a
		@echo "$(OBJ)"
		@gcc $(FLAGS) -g -o $@ -c $< -I $(INC)
		@echo "$(DARK_BLUE).\c"

lib:
		@(cd libft && make)

lib_clean:
		@(cd libft && make clean)

lib_fclean:
		@(cd libft && make fclean)

lib_re:
		@(cd libft && make re)

debug: lib $(PATH_OBJ) $(OBJ)
		@gcc $(FL_DEBUG) -o $(NAME) $(OBJ) libft/libft.a

clexec: fclean
		@echo "deleting executable"
		@rm  -f faneyer.filler

clean: lib_clean
		@/bin/rm -f $(OBJ)
		@echo "$(LIGHT_PINK)Suppression des .o de "$(NAME)"\n"

fclean: clean lib_fclean
		@/bin/rm -f $(NAME)
		@echo "$(PINK)Suppression de" $(NAME)"\n"

re: lib_re fclean all

.PHONY: all clean fclean re clexec
