#include "../actions.h"
#include "../functions.h"

void	fill_min_ar(int *min_ar, int *ndx_ar, stack *b)
{
	min_ar[0] = b -> head -> num;
	min_ar[1] = min_ar[0];
	ndx_ar[0] = 0;
	ndx_ar[1] = 0;
}

int	distance_compare(int ndx, int size)
{
	if (ndx <= size / 2)
		return (ndx);
	else
		return (size - ndx);
}

void	find_second_min(stack *b, int *min_ar, int *ndx_ar)
{
	node	*tmp;
	node	*tmp2;
	int		loc;

	tmp = b -> head;
	tmp2 = tmp;
	loc = 0;
	while (tmp)
	{
		while (tmp2)
		{
			if (min_ar[1] > tmp2 -> num)//from min < num to min > num
				min_ar[1] = tmp2 -> num;
			tmp2 = tmp2 -> next;
		}
		if (min_ar[1] < tmp -> num && tmp -> num != min_ar[0])//org min > tmp
		{
			min_ar[1] = tmp -> num;
			ndx_ar[1] = loc;
		}
		loc++;
		tmp = tmp -> next;	
	}
}

void	min_push(stack *a, stack *b, int *ndx_ar)
{
	int ndx1;
	int	ndx2;
	int	size;

	size = stackSize(b);
	ndx1 = distance_compare(ndx_ar[0], size);
	ndx2 = distance_compare(ndx_ar[1], size);
	if (ndx1 < ndx2)
	{
		go_to_index(b, a, ndx_ar[0], 'b');
		ndx_ar[1] = find_max_ndx(b);
		go_to_index(b, a, ndx_ar[1], 'b');
	}
	else
	{
		go_to_index(b, a, ndx_ar[1], 'b');
		ndx_ar[0]= find_max_ndx(b);
		go_to_index(b, a, ndx_ar[0], 'b');
	}
}

void	find_first_min(stack *a, stack *b)
{
	node	*tmp;
	int		loc;
	int		ndx_ar[2];
	int		min_ar[2];

	fill_min_ar(min_ar, ndx_ar, b);
	tmp = b -> head;
	loc = 0;
	while (tmp)
	{
		if (tmp -> num > min_ar[0])
		{
			min_ar[0] = tmp ->num;
			ndx_ar[0] = loc;
		}
		loc++;
		tmp = tmp -> next;
	}
	find_second_min(b, min_ar, ndx_ar);
	min_push(a, b, ndx_ar);
	if (a -> head -> num > a -> head -> next -> num)
		print_action("sa\n", a, b, 0);

}