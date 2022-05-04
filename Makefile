##
## EPITECH PROJECT, 2021
## MAKEFILE
## File description:
## MAKEFILE
##

SRC		=	src/add/infin_add.c				\
			src/add/infin_addsub.c			\
			src/infin_sub.c					\
			src/div_mod/infin_mod.c 		\
			src/mul/infin_mul.c 			\
			src/eval_expr/eval_expr.c		\
			src/eval_expr/free_all.c		\
			src/eval_expr/fill_array.c		\
			src/eval_expr/choice_clc.c		\
			src/eval_expr/clc.c				\
			src/eval_expr/main_ev.c 		\
			src/main.c 						\

OBJ		=	$(SRC:.c=.o)

RM		=	rm -f

LFLAGS	=	-L ./lib/my -lmy

NAME    =	calc

all: $(NAME)

$(NAME):
		make re -C ./lib/my
		gcc -o $(NAME) $(SRC) $(LFLAGS) -Wall -Wextra -g -I include

clean:
		$(RM) $(OBJ)
		make clean -C ./lib/my

fclean: clean
		$(RM) $(NAME)
		make fclean -C ./lib/my

re: fclean all
	make re -C ./lib/my

.PHONY: all clean fclean re