#include "../actions.h"
#include "../functions.h"

int	stackSize(stack *x)
{
	node	*tmp;
	int		i;

	tmp = x -> head;
	i = 0;
	while (tmp)
	{
		tmp = tmp -> next;
		i++;
	}
	return (i);
}