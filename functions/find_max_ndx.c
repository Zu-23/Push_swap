#include "../actions.h"
#include "../functions.h"

int	find_max_ndx(stack *a)
{
	int		max;
	node	*tmp;
	int		loc;
	int		ndx;

	tmp = a -> head;
	if (tmp)
		max = tmp -> num;
	ndx = 0;
	loc = 0;
	while (tmp)
	{
		if (tmp -> num > max)
		{
			max = tmp -> num;
			ndx = loc;
		}
		loc++;
		tmp = tmp -> next;
	}
	return (ndx);
}