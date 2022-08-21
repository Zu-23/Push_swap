#include "actions.h"
#include "functions.h"

void	push_swap(stack *a, stack *b)
{
	int	size;

	size = stackSize(a);
	if (size <= 3)
		three(a);
	else if (size == 5)
		five(a, b);
	else if (size > 5 && size < 500)
		hundred(a, b, size / 7);
	else if (size >= 500)
		hundred(a, b, size / 16);
}

int main(int argc, char **argv)
{
	stack	a;
	stack	b;
	int		var[2];
	int 	*array;

	a.head = NULL;
	b.head = NULL;
	array = NULL;
	var[0] = super_strlen(argv, argc); // size
	var[1] = 0;//int i
	while (++var[1] < argc)
		super_atoi(&array,argv[var[1]], var[0]);
	checkDouble(array, var[0], &a);
	push_swap(&a, &b);
}