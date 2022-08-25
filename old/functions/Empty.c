#include "../actions.h"
#include "../functions.h"

int	Empty(stack *stk)
{
	if (stk -> head == NULL)
		return (1);
	else
		return (0);
}