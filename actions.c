#include<stdlib.h>
#include "header.h"

typedef struct node
{
	int num;
	struct stack *next;
}stack;

void	push(int num, stack **top)
{
	stack *tmp;

	tmp = malloc(sizeof(stack));
	if (!tmp)
		exit (1);
	tmp->num = num;
	tmp->next = *top;
	*top = tmp;
}

int	Empty(stack *stack)
{
	if (stack == NULL)
		return (1);
	else
		return (0);
}

void	Delete(stack **Pstk )
{
	stack	*tmp;

	if (Empty(*Pstk) == 0)
	{
		tmp = *Pstk;
		*Pstk = (*Pstk)->next;
		free(tmp);
		tmp = NULL;
	}
	
}

void	swap(stack *stk)
{
	int var;

	if (Empty(stk) == 1 || stk->next == NULL)
		return (1);
	var = stk->num;
	stk->num = stk->next->num;
	stk->next->num = var;
}

void	ss(stack *stack_a, stack *stack_b)
{
	swap(stack_a);
	swap(stack_b);
}

void	pushStack(stack **stack_to_pull, stack **stack_to_push)
{
	if (Empty(*stack_to_pull))
		return (1);
	push((*stack_to_pull) -> num, stack_to_push);
	Delete(stack_to_pull);
}

void	rotate(stack **stack_a)
{
	stack	*tmp;
	stack	*top;

	if (Empty(*stack_a) || (*stack_a)->next == NULL )
        return;
	top = (*stack_a)->next;	
	tmp = *stack_a;
	while (tmp)
	{
		if (tmp->next == NULL)
		{
			tmp->next = *stack_a;
			break;
		}
		tmp = tmp->next;
	}
	(*stack_a)->next = NULL;
	*stack_a = top;
}

void	rr(stack **stack_a, stack **stack_b)
{
	rotate(stack_b);
	rotate(stack_a);
}

void	reverse(stack **stack_a)
{
	stack *tmp;

	if (Empty(*stack_a) || (*stack_a)->next == NULL )
        return;
	tmp = *stack_a;
	while (tmp)
	{
		if (tmp->next == NULL)
		{
			tmp->next = *stack_a;
			break;
		}
		tmp = tmp->next;
	}
	*stack_a = tmp;
	while (tmp)
	{
		if (tmp->next == *stack_a)
		{
			tmp->next = NULL;
			break;
		}
		tmp = tmp->next;
	}
}

void rrr(stack **stack_a, stack **stack_b)
{
	reverse(stack_a);
	reverse(stack_b);
}