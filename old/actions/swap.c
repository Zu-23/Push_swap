#include "../actions.h"
#include "../functions.h"

void	swap(stack *stk)
{
	int var;

	if (Empty(stk) == 1 || stk -> head -> next == NULL)
		return;
	var = stk -> head -> num;
	stk-> head -> num = stk -> head -> next -> num;
	stk -> head -> next -> num = var;
}