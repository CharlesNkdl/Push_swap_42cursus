CC		= gcc
CFLAGS	= -Wall -Wextra -Werror

NAME	= push_swap

SRC_PATH = Pushswap/
OBJ_PATH = obj/

SRC 	=	main.c algo.c vivalgo.c \
			libftutils.c 	libftutils2.c \
			parsing1.c 	parsing2.c	\
			push_commands1.c	push_commands2.c 	push_commands3.c \
			push_utils.c	push_utils2.c 	push_utils3.c \
			push_utils4.c 	push_utils5.c \
			parse0.c	split.c
SRCS 	=	$(addprefix $(SRC_PATH), $(SRC))
OBJ 	=	$(SRC:.c=.o)
OBJS	=	$(addprefix $(OBJ_PATH), $(OBJ))
INCS	=	-I ./includes/

all:	$(OBJ_PATH) $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
		$(CC) $(CFLAGS) -c $< -o $@ $(INCS)

$(OBJ_PATH):
		mkdir $(OBJ_PATH)

$(NAME):	$(OBJS)
		$(CC)	$(CFLAGS)	$(OBJS)	-o $(NAME)

clean:
	rm -rf $(OBJ_PATH)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re
