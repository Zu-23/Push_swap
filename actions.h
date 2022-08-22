#ifndef ACTIONS_H
# define ACTIONS_H

////change int to long for INT MAX/MIN
typedef struct node
{
	int				num;
	struct node		*next;
}node;

typedef struct stack
{
	node	*head;
}stack;

void	pushStack(stack *stack_to_pull, stack *stack_to_push);
void	swap(stack *stk);
void	rotate(stack *stk);
void	reverse(stack *stk);
void	ss(stack *a, stack *b);
void	rr(stack *a, stack *b);
void	rrr(stack *a, stack *b);

#endif