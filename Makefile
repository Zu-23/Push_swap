

SRC= actions/rrr.c \
actions/reverse.c \
actions/rotate.c \
actions/rr.c \
actions/pushStack.c \
actions/ss.c \
actions/swap.c \
functions/super_atoi.c \
functions/super_strlen.c \
functions/stackSize.c \
functions/Sortpush.c \
functions/List_to_array.c \
functions/go_to_ndx.c \
functions/find_max_ndx.c \
functions/find_min_ndx.c \
functions/find_first_min.c \
functions/five.c \
functions/hundred.c \
functions/three.c \
functions/print_action.c \
functions/push.c \
functions/Empty.c \
functions/Delete.c \
functions/checkDouble.c \

NAME=push_swap.a
HEADER_ACTION=actions.h
HEADER_FUNC=functions.h
FLAGS=-Wall -Werror -Wextra
CC=gcc -Wall -Werror -Wextra
AR= ar rcs
OBJ=$(SRC:.c=.o)
RM=rm -f

all: $(NAME)

# $(NAME): $(OBJ) $(HEADER_ACTION) $(HEADER_FUNC)
# 	$(CC) $(FLAGS) $(SRC) -o $(NAME)

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)
%.o: %.c 
	$(CC) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re