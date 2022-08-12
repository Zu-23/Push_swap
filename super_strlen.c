

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

// 

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
void	swap(stack *stk)
{
	int var;

	if (Empty(stk) == 1 || stk -> head -> next == NULL)
		return;
	var = stk -> head -> num;
	stk-> head -> num = stk -> head -> next -> num;
	stk -> head -> next -> num = var;
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
////////////////////////////////////////////////////////////////
void	fill_min_ar(int *min_ar, int *ndx_ar, stack *a)
{
	min_ar[0] = a -> head -> num;
	min_ar[1] = min_ar[0];
	ndx_ar[0] = 0;
	ndx_ar[1] = 0;
}
void	find_second_min(stack *a, int *min_ar, int *ndx_ar)
{
	node	*tmp;
	node	*tmp2;
	int		loc;

	tmp = a -> head;
	tmp2 = tmp;
	loc = 0;

	while (tmp)
	{
		while (tmp2)
		{
			if (min_ar[1] < tmp2 -> num)
				min_ar[1] = tmp2 -> num;
			tmp2 = tmp2 -> next;
		}
		if (min_ar[1] > tmp -> num && tmp -> num != min_ar[0])
		{
			min_ar[1] = tmp -> num;
			ndx_ar[1] = loc;
		}
		loc++;
		tmp = tmp -> next;	
	}
}

int	distance_compare(int ndx, int size)
{
	if (ndx <= size / 2)
		return (ndx);
	else
		return (size - ndx);
}

void go_to_index(stack *a, stack *b, int ndx);
int find_min_ndx(stack *);
int	List_to_array(stack *a, int n);

void	min_push(stack *a, stack *b, int *ndx_ar)
{
	int ndx1;
	int	ndx2;

	ndx1 = distance_compare(ndx_ar[0], a -> size);
	ndx2 = distance_compare(ndx_ar[1], a -> size);
	if (ndx1 < ndx2)
	{
		go_to_index(b, a, ndx1);
		ndx2 = find_min_ndx(a);
		go_to_index(b, a, ndx2);
	}
	else
	{
		go_to_index(b, a, ndx2);
		ndx1 = find_min_ndx(a);
		go_to_index(b, a, ndx1);
	}
}
void	find_first_min(stack *a, stack *b)
{
	node	*tmp;
	int		loc;
	int		ndx_ar[2];
	int		min_ar[2];

	fill_min_ar(min_ar, ndx_ar, a);
	tmp = a -> head;
	loc = 0;
	while (tmp)
	{
		if (tmp -> num < min_ar[0])
		{
			min_ar[0] = tmp ->num;
			ndx_ar[0] = loc;
		}
		loc++;
		tmp = tmp -> next;
	}
	find_second_min(a, min_ar, ndx_ar);
	min_push(a, b, ndx_ar);
	tmp = b -> head;
	if (b -> head -> num < b -> head -> next -> num)
		swap(b);
}



void	short_path_three(stack *a, stack *b, int *ndx_ar)
{
	int var_ar[3];
	
	var_ar[0] = a -> size;
	if (ndx_ar[0] > var_ar[0] / 2 && ndx_ar[1] <= var_ar[0] / 2)
	{
		var_ar[1] = ndx_ar[0];
		ndx_ar[0] = ndx_ar[1];
		ndx_ar[1] = var_ar[1];
	}
	else if (ndx_ar[0] <= var_ar[0] / 2 && ndx_ar[1] > var_ar[0] / 2 
			&& var_ar[0] - ndx_ar[0] >= ndx_ar[1] - var_ar[0] / 2)
		go_to_index(a, b, ndx_ar[0]);
	var_ar[2] = find_min_ndx(a);
	go_to_index(a, b, var_ar[2]);
}
void	short_path_two(stack *a, stack *b, int *ndx_ar)
{
	int	ndx[2];
	int	i;

	ndx[0] = 0;
	ndx[1] = 0;
	i = 0;
	while (ndx_ar[0] > a -> size / 2 && ndx_ar[1] > a -> size / 2 )
	{
		if (ndx[0] == ndx_ar[0])
		{
			pushStack(a, b);
			i++;
		}
		else if (ndx[1] == ndx_ar[1])
		{
			pushStack(a, b);
			i++;
		}
		else if (i == 2)
			break;
		reverse(a);
		ndx[0]++;
		ndx[1]++;
	}
}
void	short_path_one(stack *a, stack *b, int *ndx_ar)
{
	int	ndx[2];
	int	i;

	ndx[0] = 0;
	ndx[1] = 0;
	i = 0;
	while (ndx_ar[0] <= a -> size / 2 && ndx_ar[1] <= a -> size / 2 )
	{
		if (ndx[0] == ndx_ar[0])
		{
			pushStack(a, b);
			i++;
		}
		else if (ndx[1] == ndx_ar[1])
		{
			pushStack(a, b);
			i++;
		}
		else if (i == 2)
			break;
		rotate(a);
		ndx[0]++;
		ndx[1]++;
	}
}

int	find_min_ndx(stack *a)
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
int	find_max_ndx(stack *a)
{
	int		max;
	node	*tmp;
	int		loc;
	int		ndx;

	tmp = a -> head;
	max = tmp -> num;
	ndx = 0;
	loc = 0;
	while (tmp)
	{
		if (tmp -> num > max)
		{
			max = tmp -> num;
			ndx = loc;
		}
		loc++;
		tmp = tmp -> next;
	}
	return (ndx);
}
int		iterToLast(stack *x);
void	five(stack *a, stack *b);
void	chunk(stack *a, stack *b, int mid);

void	go_to_index(stack *a, stack *b, int ndx)
{
	node	*tmp;
	int		i;
	int		size;

	tmp = a -> head;
	i = 0;
	size = iterToLast(a);
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
			if (size  == ndx)
				break;
			reverse(a);
			size--;	
		}
	}
	pushStack(a, b);
}

// void	sortstack_a(stack *a, stack *b)
// {
// 	int	ndx;
// 	int	ndx_ar[2];
// 	int	min_ar[2];
// 	while (!Empty(a))
// 	{
// 		find_first_min(a, ndx_ar, min_ar);
// 		push_two_min(a, b, ndx_ar);
// 	}
// 	while (b -> head)
// 		pushStack(b, a);
// }

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
void	hundred(stack *a, stack *b, int n);
int		iterToLast(stack *x);
void	checkDouble(int *pt, int size)///////////MAIN//////////
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
	while (a.head)
		find_first_min(&a,&b);
	
	node *tmp;
	tmp = b.head;
	while (tmp)
	{
		printf("%d\n",tmp -> num);
		tmp = tmp -> next;
	}
	// size = iterToLast(&a);
	// //printf("size %d\n",a.size);
	// hundred(&a,&b, size / 7);
}
int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
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
////THE WORKING ALGO////////////////////////////////////////////////
//////////////////////////////////////////////////
void	three(stack *a, stack *b)
{
	node *tmp;
	int	ar[3];
	
	tmp = a -> head;
	ar[0] = tmp -> num;
	ar[1] = tmp -> next -> num;
	ar[2] = tmp -> next -> next -> num; 
	if ((ar[0] > ar[1]) && (ar[1] < ar[2]) && (ar[0] < ar[2]))
		swap(a);
	else if ((ar[0] > ar[1]) && (ar[1] > ar[2]) && (ar[0] > ar[2]))
	{
		swap(a);
		reverse(a);
	}
	else if ( (ar[0] > ar[1]) && (ar[1] < ar[2]) && (ar[0] > ar[2]))
		rotate(a);
	else if ((ar[0] < ar[1]) && (ar[1] > ar[2]) && (ar[0] < ar[2]))
	{
		swap(a);
		rotate(a);
	}
	else if (ar[0] < ar[1] && ar[1] > ar[2] && ar[0] > ar[2]) 
		reverse(a);
}

int	iterToLast(stack *x)
{
	node	*tmp;
	int		last;
	int		i;

	tmp = x -> head;
	i = 0;
	while (tmp)
	{
		last = tmp -> num;
		tmp = tmp -> next;
		i++;
	}
	return (i);
}


void	five(stack *a, stack *b)
{
	node	*tmp;
	int		min;
	int		max;

	min = find_min_ndx(a);
	go_to_index(a, b, min);
	max = find_max_ndx(a);
	go_to_index(a, b, max);
	three(a, b);
	pushStack(b, a);
	rotate(a);
	pushStack(b, a);
}	

void	hundred(stack *a, stack *b, int n) 
{
	int	mid;
	node *tmp;

	tmp = b -> head;
	while(a -> head)
	{ 
		mid = List_to_array(a, n);
		chunk(a, b, mid);
	}
	while (tmp)
	{
		find_first_min(a, b);
		if (tmp -> num > tmp -> next -> num)
			swap(b);
	}
	// node *tmp = a -> head;
	// while (tmp)
	// {
	// 	printf("%d\n",tmp -> num);
	// 	tmp = tmp -> next;
	// }
}
void	chunk(stack *a, stack *b, int mid)
{
	int		i;
	int		size;
	node	*tmp;

	i = 0;
	size = iterToLast(a);
	tmp = a -> head;
	while (i < size)
	{
		if (tmp -> num <= mid)
			pushStack(a, b);
		else if (i != size - 1)
			rotate(a);
		i++;
	}
	// tmp = b -> head;
	// while (tmp)
	// {
	// 	printf("chunk b %d\n",tmp -> num);
	// 	tmp = tmp -> next;
	// }
}
void arraySort(int *arr, int size)
{
    int	i;
	int	j;
	int	tmp;

	i = 0;
    while (i < size - 1)
    {
		j = 0;
        while (j < size - i - 1)
        {
            if (arr[j] > arr[j + 1])
            {
                tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
            }
            j++;
        }
        i++;
    }
}

int	lta_val_i(int size, int n)
{
	int	i;

	i = 0;
	while (1)
	{
		if (i == size - 1)
			break;
		else if (i == n - 1)
			break;
		i++;
	}
	return (i);
}

int	List_to_array(stack *a, int n)
{
	int		*ar;
	int		i;
	int		size;
	node	*tmp;

	tmp = a -> head;
	size = iterToLast(a);
	ar = malloc(sizeof(int) * size);
	i = 0;
	while (tmp)
	{
		ar[++i] = tmp -> num;
		tmp = tmp -> next;
	}
	arraySort(ar, size);
	//n will be sent from calling func and it will have value of size / x
	//while x is the value which we divide the stack
	i = lta_val_i(size, n);
	i = ar[i];
	free(ar);
	return (i);
}


int main(int argc, char **argv)
{
	stack	a;
	stack	b;
	int *array = NULL;
	int size = super_strlen(argv,argc);
	int i = 0;
	
	while (++i < argc)
		super_atoi(&array,argv[i],size);
	checkDouble(array, size);
}
