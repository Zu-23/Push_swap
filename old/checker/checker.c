#include "../actions.h"
#include "../functions.h"

void	stack_status(stack *a)
{
	node	*tmp;

	tmp = a -> head;
	while (tmp)
	{
		if (tmp -> num  > tmp -> next -> num)
		{
			printf("KO\n");
			exit(1);
		}
		tmp = tmp -> next;
	}
	printf("OK\n");
}
int	check_which_stack(char *str, stack *a, stack *b)
{
	int i;
	int	hint;

	i = 0;
	hint = 0; // a variable to check if the str has 'a' or 'b'
	while (str[i])
	{
		if (str[i] == 'a')
		{
			print_action(str, a, b);
			hint = 1;
		}
		else if (str[i] == 'b')
		{
			print_action(str, b, a);
			hint = 1;
		}
		i++;
	}
	if (hint == 0)
		print_action(str, a, b);
}
void    checker(stack *a, stack *b)
{
	char    *str;

	str = get_next_line(0);
	while (str)
	{
		check_which_stack(str, a, b);
		str = get_next_line(0);
	}
	stack_status(a);

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
	var[0] = super_strlen(argv, argc); //size
	var[1] = 0; //int i
	if (argc < 2)
		exit(1);
	while (++var[1] < argc)
		super_atoi(&array,argv[var[1]], var[0]);
	max_min_int(array, var[0]);
	checkDouble(array, var[0], &a);
	checker(&a, &b);
}