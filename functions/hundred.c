#include "../actions.h"
#include "../functions.h"

void	chunk(stack *a, stack *b, int pivot)
{
	int		i;
	int		size;

	i = 0;
	size = stackSize(a);
	while (i < size)
	{
		if (a -> head -> num <= pivot)
			print_action("pb", a, b);
		else if (i != size - 1) //to not rotate the last element which has been already checked
			print_action("ra", a, b);
		i++;
	}	
}

void	hundred(stack *a, stack *b, int n) 
{
	int		pivot;

	while (a -> head)
	{ 
		pivot = List_to_array(a, n);
		chunk(a, b, pivot);
	}
	while (b -> head)
		find_first_min(a, b);

	node *tmp;
	tmp = a -> head;
	while (tmp)
	{
		ft_printf("%d\n",tmp -> num);
		tmp = tmp -> next;
	}
}