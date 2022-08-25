#include "../actions.h"
#include "../functions.h"

int	find_max_ndx(stack *a)
{
	int		min;
	node	*tmp;
	int		loc;
	int		ndx;

	tmp = a -> head;
	min = tmp -> num;
	ndx = 0;
	loc = 0;
	while (tmp)
	{
		if (tmp -> num < min)
		{
			min = tmp -> num;
			ndx = loc;
		}
		loc++;
		tmp = tmp -> next;
	}
	return (ndx);
}