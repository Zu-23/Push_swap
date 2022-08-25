#include "../actions.h"
#include "../functions.h"

void	checkDouble(long *pt, int size, stack *a)
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
			if (i != 0)
			{
				printf("Error\n");
				exit(1);
			}
			i++;
			a -> head = top;
		}
	}
	free(pt);
}