#include "../actions.h"
#include "../functions.h"

void	Delete(stack *stk)
{
	node	*tmp;

	if (Empty(stk) == 0)
	{
		tmp = stk -> head;
		stk -> head = stk -> head -> next;
		free(tmp);
		tmp = NULL;
	}
}