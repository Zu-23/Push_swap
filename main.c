#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<header.h>
typedef struct stack
{
	int num;
	struct stack *next;
}stack;


void	push(int num, stack **top)
{
	stack *tmp;

	tmp = malloc(sizeof(stack));
	if (!tmp)
		exit (1);
	tmp->num = num;
	tmp->next = *top;
	*top = tmp;
}
//remember to treat parsers and errors
int main(int argc, char **argv)
{
	int i;
	stack *stack_a;
	stack *stack_b;

	
	i = -1;
	stack_a = NULL;
	if (argc < 2)
	{
		printf("error");
		exit(1);
	}
	while (argv[++i])
	{
		push(argv[i], &stack_a);
		if (stack_a == NULL)
			return (1);
		
	}
}

