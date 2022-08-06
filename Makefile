NAME=push_swap
HEADER_ACTION=action.h
HEADER_FUNC=func.h
FLAGS=-Wall -Werror -Wextra
CC=gcc


SRC= actions/rrr.c \
actions/reverse.c \
actions/rotate.c \
actions/rr.c \
actions/pushStack.c \
actions/ss.c \
actions/swap.c \
func/super_atoi.c \
func/super_strlen.c \
func/AllSpaces.c \
func/ft_isdigit.c \
func/Sortpush.c \
func/sort.c \
func/sortstack_a.c \
func/go_to_ndx.c \
func/find_max_ndx.c \
func/push.c \
func/Empty.c \
func/Delete.c \
func/checkDouble.c \

OBJ=$(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(HEADER_ACTION) $(HEADER_FUNC)
	$(CC) $(FLAGS) $(SRC) -o $(NAME)

clean:
	find . -name "*.o" -delete

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re