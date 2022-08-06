void	go_to_index(stack *a, stack *b, int ndx)
{
	node	*tmp;
	int		i;
	int		size;

	tmp = a -> head;
	i = 0;
	size = a -> size;
	while (1)
	{
		if (ndx <= size / 2)
		{
			if (i == ndx)
				break;
			rotate(a);
			i++;
		}
		else if (ndx > size / 2)
		{
			if (size == ndx)
				break;
			reverse(a);
			size--;	
		}
	}
	pushStack(a, b);
}