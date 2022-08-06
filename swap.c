#include "../action.h"
#include "../func.h"

void	swap(stack *stk)
{
	int var;

	if (Empty(stk -> head) == 1 || stk -> head -> next == NULL)
		return (1);
	var = stk -> head -> num;
	stk-> head -> num = stk- head -> next -> num;
	stk -> head -> next -> num = var;
}