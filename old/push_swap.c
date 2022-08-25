#include "actions.h"
#include "functions.h"

void	push_swap(stack *a, stack *b)
{
	int	size;

	size = stackSize(a);
	if (size == 2)
			if (a -> head -> num > a -> head -> next -> num)
				swap(a);
	if (size == 3)
		three(a);
	else if (size == 5)
		five(a, b);
	else if (size > 5 && size < 500)
		hundred(a, b, size / 7);
	else if (size >= 500)
		hundred(a, b, size / 16);
}
void	max_min_int(long *ar, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (ar[i] > 2147483647 || ar[i] < -2147483648)
		{
			printf("Error\n");
			exit(1);
		}
		i++;
	}
}
int main(int argc, char **argv)
{
	stack	a;
	stack	b;
	int		var[2];
	long 	*array;

	a.head = NULL;
	b.head = NULL;
	array = NULL;
	var[0] = super_strlen(argv, argc); // size
	var[1] = 0;//int i
	while (++var[1] < argc)
		super_atoi(&array,argv[var[1]], var[0]);
	max_min_int(array, var[0]);
	checkDouble(array, var[0], &a);
	push_swap(&a, &b);
}