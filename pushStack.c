#include "../action.h"
#include "../func.h"

void	pushStack(stack *stack_to_pull, stack *stack_to_push)
{
	if (Empty(stack_to_pull -> head))
		return (1);
	push(stack_to_pull -> head -> num, stack_to_push);
	Delete(stack_to_pull);
}