# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zhaddoum <zhaddoum@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/26 16:28:08 by zhaddoum          #+#    #+#              #
#    Updated: 2022/08/28 21:51:17 by zhaddoum         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #



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
functions/max_min_int.c \
get_next_line/get_next_line.c \

NAME=ObjectPushSwap.a
COMPILE=Push_swap
BONUS=bonus
CC=gcc -Wall -Werror -Wextra
AR= ar rcs
OBJ=$(SRC:.c=.o)
RM=rm -f

all: $(NAME) $(COMPILE) $(BONUS)

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)

%.o: %.c 
	$(CC) -c $< -o $@

$(COMPILE): $(NAME)
	cd ft_printf && make
	$(CC) main.c $(NAME) ft_printf/libftprintf.a -o $(COMPILE)

$(BONUS): $(NAME) 
	$(CC) checker_bonus.c $(NAME) ft_printf/libftprintf.a -o checker

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME) $(COMPILE) checker

re: fclean all

.PHONY: all bonus clean fclean re