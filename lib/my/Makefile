##
## EPITECH PROJECT, 2021
## MAKEFILE
## File description:
## MAKEFILE
##

NAME    =	libmy

SRC		=	my_atoi.c 				 \
			my_getnbr.c				 \
			my_itoa.c 				 \
			my_put_nbr.c 			 \
			my_putchar.c 			 \
			my_putstr.c 			 \
			my_revstr.c 	 		 \
			my_str_isnum.c 			 \
			my_strcmp.c 			 \
			my_strcpy.c 			 \
			my_strdup.c 			 \
			my_strlen.c 			 \

OBJ		=	$(SRC:.c=.o)

RM		=	rm -f

all: $(NAME)

$(NAME): $(OBJ)
		ar rc $(NAME).a $(OBJ)
		$(RM) $(OBJ)
		cp my.h ../../include
		cp $(NAME).a ../


clean:
		$(RM) $(OBJ)

fclean: clean
		$(RM) $(NAME).a
		$(RM) ../$(NAME).a
		$(RM) ../../include/my.h

re: fclean all

.PHONY: all clean fclean re