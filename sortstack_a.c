void	sortstack_a(stack *a, stack *b)
{
	int	ndx;
	while (!Empty(a))
	{
		ndx = find_max_ndx(a);
		go_to_index(a, b, ndx);
	}
	while (b -> head)
		pushStack(b, a);
}