#include<stdio.h>
#include<stdlib.h>
typedef struct stack
{
    int num;
    struct stack *next;
}stack;

void    push(int num, stack **top)
{
    stack *tmp;

    tmp = malloc(sizeof(stack));
    if (!tmp)
        exit (1);
    tmp->num = num;
    tmp->next = *top;
    *top = tmp;
}

void	reverse(stack **stack_a)
{
	stack *tmp;

	tmp = *stack_a;
	while (tmp)
	{
		if (tmp->next == NULL)
		{
			tmp->next = *stack_a;
			break;
		}
		tmp = tmp->next;
	}
	*stack_a = tmp;
	while (tmp)
	{
		if (tmp->next == *stack_a)
		{
			tmp->next = NULL;
			break;
		}
		tmp = tmp->next;
	}
}
int main() {
  stack *stack_a;
  stack *tmp;
  stack_a = NULL;
  
  push(1,&stack_a);
  push(2,&stack_a);
  push(3,&stack_a);
  tmp = stack_a;
  while (tmp)
  {
      printf("%d\n",tmp->num);
      tmp = tmp->next;
  }
  reverse(&stack_a);
  tmp = stack_a;
  printf("------------------\n");
  while (tmp)
  {
      printf("%d\n",tmp->num);
      tmp = tmp->next;
  }
  return 0;
}

