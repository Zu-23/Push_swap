#include "../actions.h"
#include "../functions.h"

void	push(int num, stack *top)
{
	node *tmp;
	tmp = malloc(sizeof(node));
	if (!tmp)
		exit (1);
	tmp -> num = num;
	tmp -> next = top -> head;
	top -> head = tmp;
}