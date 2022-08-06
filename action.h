#ifndef ACTION_H
# define ACTION_H

#include<stdio.h>//remove later
#include<unistd.h>
#include<stdlib.h>
#include "func.h"
typedef struct node
{
	int			num;
	struct node	*next;
}node;

typedef struct stack
{
	node	*head;
	int		size;
}stack;

void	pushStack(stack *stack_to_pull, stack *stack_to_push);
void	swap(stack *stk);
void	rotate(stack *stk);
void	reverse(stack *stk);
void	ss(stack *a, stack *b);
void	rr(stack *a, stack *b);
void	rrr(stack *a, stack *b);

#endif