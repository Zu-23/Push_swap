#include "../actions.h"
#include "../functions.h"

void	checkDouble(int *pt, int size, stack *a)
{
	int		i;
	node 	*top;

	i = 0;
	push(pt[0], a);
	top = a -> head;
	while (i < size)
	{
		if (pt[i] != a -> head -> num)
		{
			if (a -> head -> next == NULL)
			{
				Sortpush(pt[i], a);
				i++;
				a -> head = top;
			}
			else
				a -> head = a -> head -> next;
		}
		else if (pt[i] == a -> head -> num)
		{
			i++;
			a -> head = top;
		}
	}
	free(pt);
}