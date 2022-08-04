/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhaddoum <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 11:47:06 by zhaddoum          #+#    #+#             */
/*   Updated: 2021/11/23 10:45:59 by zhaddoum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int 		num;
	struct node *next;
}node;

typedef struct stack
{
	node *head;
	int size;
}stack;

//we can calculate the elemnts by making a function that keeps dividing 
//the total number of the radnom number then keep dividing and storing
// int	*treatElement(int elem)
// {
// 	int	i;
// 	int	size;
// 	int	*ar;
// 	int	c;

// 	i = elem;
// 	while (i)
// 	{
// 		i /= 2;
// 		size++;
// 	}
// 	ar = malloc(sizeof(int) * size);
// 	i = elem;
// 	while (c < size)
// 	{
// 		ar[c] = i / 2;
// 		i /= 2;
// 		c++;
// 	}
// 	return (ar);
// }

// typedef struct chunk
// {
// 	int	mid;
// 	int	elem; 10-5-3
// }chunk;


// void	sortStackB(stack **stack_a, stack **stack_b, int elem)
// {
// 	int	*elemPtr;
// 	int	size;
// 	int	mid;

// 	elemPtr = treatElement(elem);
// 	size = sizeof(elemPtr) / 4;
// 	while (--size)
// 	{
// 		if (elemPtr[size] == 1)
// 			pushStack(stack_a);
// 		else
// 		{
// 			mid = chunkSorting(elemPtr[size], stack_b);
// 			while (elemPtr[size])
// 			{
// 				if ((*stack_b) -> num > mid)
// 				{
// 					pushStack(stack_b, stack_a);
// 					elemPtr[size] -= 1;
// 				}
// 			}
// 		}
// 	}
// }

// void	sortStackA(stack **stack_a, stack **stack_b, int mid, int elem)
// {
// 	stack 	*tmp;
// 	int		i;

// 	i = 0;
// 	tmp = *stack_a;
// 	if (!peepStack(stack_a))
// 	{
// 		miniSort(stack_a);
// 		functosort();
// 	}
// 	//we need to keep track of the number of elem for each chunk
// 	while (i < elem)
// 	{
// 		 if (tmp -> num < mid)
// 		 {
// 			pushStack(stack_a, stack_b);
// 			i++;
// 		 }
// 		 else
// 		 {
// 			tmp = iterToLast(stack **stack_a);
// 			if (tmp -> num >= mid)
// 				rotate(stack_a);
// 			else if (tmp -> num < mid)
// 			{
// 				reverse(stack_a);
// 				pushStack(stack_a, stack_b);
// 				i++;
// 			}
// 		 }
// 	}
// 	List_to_array(stack_a, stack_b);
// }

// int	List_to_array(stack **stack_a, stack **stack_b)
// {
// 	int	size;
// 	stack *head;
// 	int	*ar;
// 	int	i;

// 	i = 0;
// 	head = *stack_a;
// 	size = 0;
// 	while (head)
// 	{
// 		size++;
// 		head = head -> next;
// 	}
// 	ar = malloc(sizeof(int) * size);
// 	head = *stack_a;
// 	while (head)
// 	{
// 		ar[i] = head -> num;
// 		head = head -> next;
// 		i++;
// 	}
// 	i = sort(&ar, size);
// 	size = ar[size / 2];
// 	free(ar);
// 	sortStack(stack_a, stack_b, size, i);
// }

// void sort(stack** head)
// {
//   stack	*current;
//   stack	*index;
//   int	temp;

//   current = *head;
//   if (head == NULL)
//     return ;
//   else 
//   {
// 	  while (current != NULL)
// 	  {
// 		  index = current->next;
// 		  while (index != NULL)
// 		  {
// 			  if (current->num > index->num)
// 			  {
// 				  temp = current->num;
// 				  current->num = index->num;
// 				  index->num = temp;
// 			  }
// 			  index = index->next;
// 		  }
// 		current = current->next;
// 	  }
//   }
// }
/////////////////////////////////////////////////////////////////////////////////////////////////////
int	Empty(stack *stk)
{
	if (stk -> head == NULL)
		return (1);
	else
		return (0);
}
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

void	reverse(stack *stk)
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

void	pushStack(stack *stack_to_pull, stack *stack_to_push)
{
	if (Empty(stack_to_pull))
		return;
	push(stack_to_pull -> head -> num, stack_to_push);
	Delete(stack_to_pull);
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int	find_max_ndx(stack *a)
{
	int		min;
	node	*tmp;
	int		loc;
	int		ndx;

	tmp = a -> head;
	min = tmp -> num;
	ndx = 0;
	loc = 0;
	while (tmp)
	{
		if (tmp -> num < min)
		{
			min = tmp -> num;
			ndx = loc;
		}
		loc++;
		tmp = tmp -> next;
	}
	return (ndx);
}

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

void	sortstack_a(stack *a, stack *b)
{
	int	ndx;
	while (!Empty(a))
	{
		ndx = find_max_ndx(a);
		go_to_index(a, b, ndx);
		pushStack(a, b);
	}
	printf("%p\n",b->head);
	while (!Empty(b))
	{
		pushStack(b, a);
		printf("%d\n",b->head->num);
	}
	printf("before while\n");
	while (b -> head)
	{
		printf("hello 4\n");
		printf("%d\n", b -> head -> num);
		b -> head = b -> head -> next;
	}
}

int sort(int **ar, int size)
{
    int 	i;
    int 	j;
    int 	tmp;

    i = 0;
    j = 0;
    while (j < size - 1)
    {
        while (i < size - j - 1)
        {
            if (*ar[i] > *ar[i + 1])
            {
                tmp = *ar[i];
                *ar[i] = *ar[i + 1];
                *ar[i + 1] = tmp;
            }
            i++;
        }
        j++;
    }
	return (size / 2);
}
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

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

void	checkDouble(int *pt, int size)
{
	int		i;
	stack	a;
	stack	b;
	node 	*top;

	a.head = NULL;
	b.head = NULL;
	i = 0;
	push(pt[0], &a);
	top = a.head;
	while (i < size)
	{
		if (pt[i] != a.head -> num)
		{
			if (a.head -> next == NULL)
			{
				Sortpush(pt[i], &a);
				i++;
				a.head = top;
			}
			else
				a.head = a.head -> next;
		}
		else if (pt[i] == a.head -> num)
		{
			i++;
			a.head = top;
		}
	}
	free(pt);
	sortstack_a(&a, &b);
}

int	AllSpaces(char c)
{
	if ((c == '\t') || (c == '\n') || (c == '\v')
		|| (c == '\f') || (c == ' ') || (c == '\r'))
		return (0);
	return (1);
}


int	super_strlen(char **str, int argc)
{
	int	i;
	int	count;
	int	k;

	i = 1;
	count = 0;
	k = 0;
	
	while (i < argc)
	{
		while (ft_isdigit(str[i][k]) == 1 || str[i][k] == '-')
		{
			k++;
			if (str[i][k] == ' ')
			{
				count++;
				k++;
			}
			else if (str[i][k] == '\0')
				count++;
		}
		if (str[i][k] != '\0')
		{
			printf("Error\n");
			exit(1);
		}
		k = 0;
		i++;	
	}
	return (count);
}

void    super_atoi(int **ar, char *ptr, int count)
{
    long			i;
    int				ret;
    int				sign;
    static int		k;
    int				j;

    i = 0;
    ret = 0;
    j = 0;
    sign = 1;
    if (!*ar)
        *ar = malloc(sizeof(int) * count);
    while(ptr[i])
    {
        if (ptr[i] == '-' || ptr[i] == '+')
        {
            if (ptr[i] == '-')
                sign *= -1;
            i++;
        }
        while (ptr[i] >= '0' && ptr[i] <= '9')
        {
            ret = ret * 10 + (ptr[i] - 48);
            i++;
        }
        if (AllSpaces(ptr[i]) == 0)
        {
            i++;
            ar[0][k] = ret * sign;
            sign = 1;
            ret = 0;
            k++;
        }
    
    }
    ar[0][k] = ret * sign;
    k++; 
}


int main(int argc, char **argv)
{
	int *array = NULL;
	int size = super_strlen(argv,argc);
	int i = 0;
	
	while (++i < argc)
		super_atoi(&array,argv[i],size);
	checkDouble(array, size);
	
}
