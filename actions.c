#include<stdlib.h>
#include "header.h"
//https://pythontutor.com/render.html#code=%23include%3Cstdio.h%3E%0A%23include%3Cstdlib.h%3E%0Atypedef%20struct%20node%0A%7B%0A%20%20%20%20int%20num%3B%0A%20%20%20%20struct%20node%20*next%3B%0A%7Dnode%3B%0A%0Atypedef%20struct%20stack%0A%7B%0A%20%20%20%20node%20*head%3B%0A%20%20%20%20int%20size%3B%0A%7Dstack%3B%0Avoid%20%20push%28stack%20*a%29%0A%7B%0A%20%20%20%20//%20printf%28%22inside%20push%20%25p%5Cn%22,*a%20-%3Ehead%29%3B%0A%0A%20%20node%20*tmp%20%3D%20%28node%20*%29%20malloc%28sizeof%28node%29%29%3B%0A%20%20tmp%20-%3E%20num%20%3D%204%3B%0A%20%20tmp%20-%3E%20next%20%3D%20a-%3Ehead%3B%0A%20%20a-%3Ehead%20%3D%20tmp%3B%20%20%0A%7D%0Aint%20main%28%29%0A%7B%0A%20%20node%20*%20k%20%3D%20%28node%20*%29%20malloc%28sizeof%28node%29%29%3B%0Anode%20*%20l%20%3D%20%28node%20*%29%20malloc%28sizeof%28node%29%29%3B%0Ak-%3Enum%20%3D%209%3B%0Ak-%3Enext%3D%20NULL%3B%0Al-%3Enum%20%3D%2084%3B%0Ak-%3Enext%3D%20NULL%3B%0Ak-%3Enext%20%3D%20l%3B%0A%0Astack%20a%20%3B%0Aa.head%20%3D%20k%3B%0A%0A%0Anode%20*%20n%20%3D%20%28node%20*%29%20malloc%28sizeof%28node%29%29%3B%0An-%3Enum%20%3D%2011%3B%0An-%3Enext%20%3D%20a.head%3B%0Aa.head%20%3D%20n%3B%0Aprintf%28%22add%20of%20a.head%20%25p%5Cn%22,a.head%29%3B%0Apush%28%26a%29%3B%0A%20%20return%200%3B%0A%7D&cumulative=false&curInstr=23&heapPrimitives=nevernest&mode=display&origin=opt-frontend.js&py=c_gcc9.3.0&rawInputLstJSON=%5B%5D&textReferences=false
// typedef struct stack
// {
// 	int num;
// 	struct stack *next;
// }stack;

typedef struct node
{
	int num;
	struct node *next;
}node;

typedef struct stack
{
	node *head;
	int size;
}stack;


void	push(int num, stack *top)
{
	node *tmp;

	tmp = malloc(sizeof(node));
	if (!tmp)
		exit (1);
	tmp -> num = num;
	tmp -> next = top -> head;
	top -> head = tmp;
	top -> size += 1;
}

int	peepStack(stack x)
{
	node	*tmp;

	tmp = x -> head;
	if (tmp -> next -> next = NULL)
		return (0);
	return (1);
}

int	Empty(stack *stk)
{
	if (stk -> head == NULL)
		return (1);
	else
		return (0);
}

void	Delete(stack *stk)
{
	node	*tmp;

	if (Empty(stk) == 0)
	{
		tmp = stk -> head;
		stk -> head = stk -> head -> next;
		free(tmp);
		tmp = NULL;
	}
}

void	swap(stack *stk)
{
	int var;

	if (Empty(stk -> head) == 1 || stk -> head -> next == NULL)
		return (1);
	var = stk -> head -> num;
	stk-> head -> num = stk- head -> next -> num;
	stk -> head -> next -> num = var;
}

void	ss(stack *a, stack *b)
{
	swap(a);
	swap(b);
}

void	pushStack(stack *stack_to_pull, stack *stack_to_push)
{
	if (Empty(stack_to_pull -> head))
		return (1);
	push(stack_to_pull -> head -> num, stack_to_push);
	Delete(stack_to_pull);
}

void	rotate(stack *stk)
{
	node	*tmp;
	node	*top;

	if (Empty(stk) || stk -> head ->next == NULL )
        return;
	top = stk -> head -> next;	
	tmp = stk -> head;
	while (tmp)
	{
		if (tmp -> next == NULL)
		{
			tmp -> next = stk -> head;
			break;
		}
		tmp = tmp -> next;
	}
	stk -> head -> next = NULL;
	stk -> head = top;
}

void	rr(stack *a, stack *b)
{
	rotate(b);
	rotate(a);
}

void	reverse(stack stk)
{
	node	*tmp;

	if (Empty(stk) || stk -> head -> next == NULL )
        return;
	tmp = stk -> head;
	while (tmp)
	{
		if (tmp -> next == NULL)
		{
			tmp -> next = stk -> head;
			break;
		}
		tmp = tmp -> next;
	}
	stk -> head = tmp;
	while (tmp)
	{
		if (tmp -> next == stk -> head)
		{
			tmp -> next = NULL;
			break;
		}
		tmp = tmp -> next;
	}
}

void rrr(stack *a, stack *b)
{
	reverse(a);
	reverse(b);
}