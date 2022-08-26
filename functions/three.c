#include "../actions.h"
#include "../functions.h"

void	three(stack *a)
{
	node	*tmp;
	int		ar[3];
	
	tmp = a -> head;
	ar[0] = tmp -> num;
	ar[1] = tmp -> next -> num;
	ar[2] = tmp -> next -> next -> num; 
	if ((ar[0] > ar[1]) && (ar[1] < ar[2]) && (ar[0] < ar[2]))
		print_action("sa\n", a, NULL, 0);
	else if ((ar[0] > ar[1]) && (ar[1] > ar[2]) && (ar[0] > ar[2]))
	{
		print_action("sa\n", a, NULL, 0);
		print_action("rra\n", a, NULL, 0);
	}
	else if ( (ar[0] > ar[1]) && (ar[1] < ar[2]) && (ar[0] > ar[2]))
		print_action("ra\n", a, NULL, 0);
	else if ((ar[0] < ar[1]) && (ar[1] > ar[2]) && (ar[0] < ar[2]))
	{
		print_action("sa\n", a, NULL, 0);
		print_action("ra\n", a, NULL, 0);
	}
	else if (ar[0] < ar[1] && ar[1] > ar[2] && ar[0] > ar[2]) 
		print_action("rra\n", a, NULL, 0);
}