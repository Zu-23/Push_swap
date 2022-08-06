void	Sortpush(int num, stack *top)
{
	node *tmp;

	tmp = malloc(sizeof(node));
	if (!tmp)
		exit (1);
	tmp -> num = num;
	tmp -> next = NULL;
	top -> size += 1;
	if (top -> head != NULL )
		top -> head -> next = tmp;
	else	
		top -> head = tmp;
}
