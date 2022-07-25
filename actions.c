#include<stdlib.h>
#include "header.h"

typedef struct stack
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

void	sa(stack *stk)
{
	int var;

	if (Empty(stk) == 1 || stk->next == NULL)
		return (1);
	var = stk->num;
	stk->num = stk->next->num;
	stk->next->num = var;
}

void	sb(stack *stk)
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
	sa(stack_a);
	sb(stack_b);
}

void	pa(stack **stack_b, stack **stack_a)
{
	if (Empty(*stack_b) == 1)
		return (1);
	push((*stack_b)->num, stack_a);
	Delete(stack_b);
}

void	pa(stack **stack_b, stack **stack_a)
{
	if (Empty(*stack_a) == 1)
		return (1);
	push((*stack_a)->num, stack_b);
	Delete(stack_a);
}

void	ra(stack **stack_a)
{
	stack	*tmp;
	stack	*top;

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

void	rb(stack **stack_b)
{
	stack	*tmp;
	stack	*top;

	top = (*stack_b)->next;	
	tmp = *stack_b;
	while (tmp)
	{
		if (tmp->next == NULL)
		{
			tmp->next = *stack_b;
			break;
		}
		tmp = tmp->next;
	}
	(*stack_b)->next = NULL;
	*stack_b = top;
}

void	rr(stack **stack_a, stack **stack_b)
{
	rb(stack_b);
	ra(stack_a);
}
void	rra(stack **stack_a)
{
	stack *tmp;

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

void	rrb(stack **stack_b)
{
	stack *tmp;

	tmp = *stack_b;
	while (tmp)
	{
		if (tmp->next == NULL)
		{
			tmp->next = *stack_b;
			break;
		}
		tmp = tmp->next;
	}
	*stack_b = tmp;
	while (tmp)
	{
		if (tmp->next == *stack_b)
		{
			tmp->next = NULL;
			break;
		}
		tmp = tmp->next;
	}
}

void rrr(stack **stack_a, stack **stack_b)
{
	rra(*stack_a);
	rrb(*stack_b);
}