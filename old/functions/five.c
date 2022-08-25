#include "../actions.h"
#include "../functions.h"

void	five(stack *a, stack *b)
{
	int		min;
	int		max;

	min = find_min_ndx(a);
	go_to_index(a, b, min, 'a');
	max = find_max_ndx(a);
	go_to_index(a, b, max, 'a');
	three(a);
	print_action("pa", b, a);
	print_action("ra", a, NULL);
	print_action("pa", b, a);
}	