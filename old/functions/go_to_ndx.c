#include "../actions.h"
#include "../functions.h"

void	go_to_index(stack *a, stack *b, int ndx, char c)
{
	int		i;
	int		size;

	i = 0;
	size = stackSize(a);
	while (1)
	{
		if (ndx <= size / 2)
		{
			if (i == ndx)
				break;
			print_action_aux("r", c, a, b);
			i++;
		}
		else if (ndx > size / 2)
		{
			if (size  == ndx)
				break;
			print_action_aux("rr", c, a, b);
			size--;	
		}
	}
	print_action_aux("p", c, a, b);//need to be changed
}