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
}stack;


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
int		stackSize(stack *x);
void	five(stack *a, stack *b);
void	chunk(stack *a, stack *b, int mid);
void 	go_to_index(stack *a, stack *b, int ndx, char g);
int 	find_min_ndx(stack *);
int		List_to_array(stack *a, int n);
void	hundred(stack *a, stack *b, int n);
void	print_action(char *str, stack *a, stack *b);
void	print_action_aux(char *, char , stack *, stack *);

void	fill_min_ar(int *min_ar, int *ndx_ar, stack *b)
{
	min_ar[0] = b -> head -> num;
	min_ar[1] = min_ar[0];
	ndx_ar[0] = 0;
	ndx_ar[1] = 0;
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
	int	i;

	i = -1;
	if (ndx <= size / 2)
		return (ndx);
	else
		return (size - ndx);
}

///fix the problem of pritning actions
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
		ndx_ar[1] = find_min_ndx(b);
		go_to_index(b, a, ndx_ar[1], 'b');
	}
	else
	{
		go_to_index(b, a, ndx_ar[1], 'b');
		ndx_ar[0]= find_min_ndx(b);
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
		if (tmp -> num < min_ar[0])
		{
			min_ar[0] = tmp ->num;
			ndx_ar[0] = loc;
		}
		loc++;
		tmp = tmp -> next;
	}
	find_second_min(b, min_ar, ndx_ar);
	min_push(a, b, ndx_ar);
	if (a -> head -> num < a -> head -> next -> num)
		swap(a);

}

int	find_min_ndx(stack *a)
{
	int		min;
	node	*tmp;
	int		loc;
	int		ndx;

	tmp = a -> head;
	if (tmp)
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
	if (tmp)
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

void	go_to_index(stack *a, stack *b, int ndx, char c)
{
	node	*tmp;
	int		i;
	int		size;

	tmp = a -> head;
	i = 0;
	size = stackSize(a);
	while (1)
	{
		if (ndx <= size / 2)
		{
			if (i == ndx)
				break;
			print_action_aux("r", c, a, b);
			i++;
		}
		else if (ndx > size / 2)
		{
			if (size  == ndx)
				break;
			print_action_aux("rr", c, a, b);
			size--;	
		}
	}
	print_action_aux("p", c, a, b);//need to be changed
}

void	Sortpush(int num, stack *top)
{
	node *tmp;

	tmp = malloc(sizeof(node));
	if (!tmp)
		exit (1);
	tmp -> num = num;
	tmp -> next = NULL;
	if (top -> head != NULL )
		top -> head -> next = tmp;
	else
		top -> head = tmp;
}

void	checkDouble(int *pt, int size, stack *a, stack *b)///////////MAIN////////////!!!!!!!!!!!!!!!!!!!!!!!??????!!!???!?!?!?!?!??!?!?!?!?!?!?!?!?!?
{
	int		i;
	node 	*top;

	i = 0;
	push(pt[0], a);
	top = a -> head;
	while (i < size)
	{
		if (pt[i] != a -> head -> num)
		{
			if (a -> head -> next == NULL)
			{
				Sortpush(pt[i], a);
				i++;
				a -> head = top;
			}
			else
				a -> head = a -> head -> next;
		}
		else if (pt[i] == a -> head -> num)
		{
			i++;
			a -> head = top;
		}
	}
	free(pt);
	//size = stackSize(a);
	//hundred(a,b,size / 7);
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

// void    super_atoi(int **ar, char *ptr, int count)
// {
//     long			i;
//     int				ret;
//     int				sign;
//     static int		k;
//     int				j;

//     i = 0;
//     ret = 0;
//     j = 0;
//     sign = 1;
//     if (!*ar)
//         *ar = malloc(sizeof(int) * count);
//     while(ptr[i])
//     {
//         if (ptr[i] == '-' || ptr[i] == '+')
//         {
//             if (ptr[i] == '-')
//                 sign *= -1;
//             i++;
//         }
//         while (ptr[i] >= '0' && ptr[i] <= '9')
//         {
//             ret = ret * 10 + (ptr[i] - 48);
//             i++;
//         }
//         if (AllSpaces(ptr[i]) == 0)
//         {
//             i++;
//             ar[0][k] = ret * sign;
//             sign = 1;
//             ret = 0;
//             k++;
//         }
    
//     }
//     ar[0][k] = ret * sign;
//     k++; 
// }
typedef struct super_atoi_var
{
   int	j;
   long	ret;
   int	sign;
}var;

void     after_int(char c, var *var, int *i)
{
    if (c == '-' || c == '+')
    {
        if (c == '-')
            var -> sign *= -1;
        *i += 1;
    }
}
void    super_atoi(int **ar, char *ptr, int count)
{
    int				i;
    static int		k;
	var var;
 
	var.ret = 0;
	var.j = 0;
	var.sign = 1;
    i = 0;
    if (!*ar)
        *ar = malloc(sizeof(int) * count);
    while(ptr[i])
    {
        after_int(ptr[i], &var, &i);
        while (ptr[i] >= '0' && ptr[i] <= '9')//we changed i incr in ptr[i] it might cause prob
            var.ret = var.ret * 10 + (ptr[i++] - 48);
        if (ptr[i] && AllSpaces(ptr[i++]) == 0)//another doubt of prob ptr[i++]
        {
            ar[0][k++] = var.ret * var.sign; //potential prob k++
            var.sign = 1;
            var.ret = 0;
        }
    }
    ar[0][k] = var.ret * var.sign;
    k++; 
}

////THE WORKING ALGO//////////////////////////////////////////////////////////////////////////////////////////////////

void	three(stack *a, stack *b)
{
	node *tmp;
	int	ar[3];
	
	tmp = a -> head;
	ar[0] = tmp -> num;
	ar[1] = tmp -> next -> num;
	ar[2] = tmp -> next -> next -> num; 
	if ((ar[0] > ar[1]) && (ar[1] < ar[2]) && (ar[0] < ar[2]))
		print_action("sa", a, NULL);
	else if ((ar[0] > ar[1]) && (ar[1] > ar[2]) && (ar[0] > ar[2]))
	{
		print_action("sa", a, NULL);
		print_action("rra", a, NULL);
	}
	else if ( (ar[0] > ar[1]) && (ar[1] < ar[2]) && (ar[0] > ar[2]))
		print_action("ra", a, NULL);
	else if ((ar[0] < ar[1]) && (ar[1] > ar[2]) && (ar[0] < ar[2]))
	{
		print_action("sa", a, NULL);
		print_action("ra", a, NULL);
	}
	else if (ar[0] < ar[1] && ar[1] > ar[2] && ar[0] > ar[2]) 
		print_action("rra", a, NULL);
}

int	stackSize(stack *x)
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
	go_to_index(a, b, min, 'a');
	max = find_max_ndx(a);
	go_to_index(a, b, max, 'a');
	three(a, b);
	print_action("pa", b, a);
	print_action("ra", a, NULL);
	print_action("pa", b, a);
}	

void	hundred(stack *a, stack *b, int n) 
{
	int		pivot;
	node 	*tmp;

	while (a -> head)
	{ 
		pivot = List_to_array(a, n);
		chunk(a, b, pivot);
	}
	while (b -> head)
		find_first_min(a, b);
	tmp = a -> head;
	while (tmp)
	{
		printf("%d\n",tmp -> num);
		tmp = tmp -> next;
	}
}

void	chunk(stack *a, stack *b, int pivot)
{
	int		i;
	int		size;
	node	*tmp;

	i = 0;
	size = stackSize(a);
	while (i < size)
	{
		if (a -> head -> num <= pivot)
			print_action("pb", a, b);
		else if (i != size - 1) //to not rotate the last element which has been already checked
			print_action("ra", a, b);
		i++;
	}	
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
	size = stackSize(a);
	ar = malloc(sizeof(int) * size);
	i = 0;
	while (tmp)
	{
		ar[i++] = tmp -> num;
		tmp = tmp -> next;
	}
	arraySort(ar, size);
	i = lta_val_i(size, n);
	i = ar[i];
	free(ar);
	return (i);
}

void	print_action_aux(char *str, char c, stack *x, stack *y)
{
	if (c == 'a')
	{
		if (str == "r")
			print_action("ra",x, y);
		else if (str == "rr")
			print_action("rra", x, y);
		else if (str == "p")
			print_action("pa", x, y);
	}
	else if (c == 'b')
	{
		if (str == "r")
			print_action("rb",x, y);
		else if (str == "rr")
			print_action("rrb", x, y);
		else if (str == "p")
			print_action("pb", x, y);
	}
}
void	print_action(char *str, stack *x, stack *y)
{
	static int i;
	
	printf("%s\n",str);
	if (str == "sa" || str == "sb")
	{
		swap(x);
		i++;
	}
	// else if (str == "ss")
	// 	ss(x, y);
	else if (str == "ra" || str == "rb")
	{
		rotate(x);
		i++;
	}
	// else if (str == "rr")
	// 	rr(x, y);
	else if (str == "rra" || str == "rrb")
	{
		reverse(x);
		i++;
	}
	// else if (str == "rrr")
	// 	rrr(x, y);
	else if (str = "pa", str = "pb")
	{
		pushStack(x, y);
		i++;
	}
	printf("%d\n",i);
}
//dont forget treating MAX INT as arg
void	push_swap(stack *a, stack *b)
{
	int	size;

	size = stackSize(a);
	if (size <= 3)
		three(a, b);
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
	checkDouble(array, var[0], &a, &b);
	push_swap(&a, &b);
}
