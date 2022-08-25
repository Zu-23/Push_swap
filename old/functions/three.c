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
		print_action("sa", a, NULL);
	else if ((ar[0] > ar[1]) && (ar[1] > ar[2]) && (ar[0] > ar[2]))
	{
		print_action("sa", a, NULL);
		print_action("rra", a, NULL);
	}
	else if ( (ar[0] > ar[1]) && (ar[1] < ar[2]) && (ar[0] > ar[2]))
		print_action("ra", a, NULL);
	else if ((ar[0] < ar[1]) && (ar[1] > ar[2]) && (ar[0] < ar[2]))
	{
		print_action("sa", a, NULL);
		print_action("ra", a, NULL);
	}
	else if (ar[0] < ar[1] && ar[1] > ar[2] && ar[0] > ar[2]) 
		print_action("rra", a, NULL);
}