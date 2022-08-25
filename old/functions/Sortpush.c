#include "../actions.h"
#include "../functions.h"

void	Sortpush(int num, stack *top)
{
	node *tmp;

	tmp = malloc(sizeof(node));
	if (!tmp)
		exit (1);
	tmp -> num = num;
	tmp -> next = NULL;
	if (top -> head != NULL )
		top -> head -> next = tmp;
	else	
		top -> head = tmp;
}
