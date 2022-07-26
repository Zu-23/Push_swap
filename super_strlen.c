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
	int num;
	struct stack *next;
}stack;

typedef struct chunk
{
	int	mid;
	int	elem;
}chunk;

void	sortStack(stack **stack_a, stack **stack_b, chunk a)
{
	stack *tmp;
	int	i;

	i = 0;
	tmp = *stack_a;
	while (i < elem)
	{
		 if (tmp -> num < mid)
		 {
			pushStack(stack_a, stack_b);
			i++;
		 }
		 else
		 	rotate(stack_a);
	}
	List_to_array(stack_a);
}

int	List_to_array(stack **stack_a)
{
	int	size;
	stack *head;
	int	*ar;
	int	i;

	i = 0;
	head = *stack_a;
	size = 0;
	while (head)
	{
		size++;
		head = head -> next;
	}
	ar = malloc(sizeof(int) * size);
	head = *stack_a;
	while (head)
	{
		ar[i] = head -> num;
		head = head -> next;
		i++;
	}
	sort(ar, size);
	free(ar);
}
int sort(int *ar, int size)
{
    int 	i;
    int 	j;
    int 	tmp;
	chunk	a;

    i = 0;
    j = 0;
    while (j < size - 1)
    {
        while (i < size - j - 1)
        {
            if (ar[i] > ar[i + 1])
            {
                tmp = ar[i];
                ar[i] = ar[i + 1];
                ar[i + 1] = tmp;
            }
            i++;
        }
        j++;
    }
	a.mid = ar[size / 2];
	a.elem = size / 2;
}
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

void	Sortpush(int num, stack **top)
{
	stack *tmp;

	tmp = malloc(sizeof(stack));
	if (!tmp)
		exit (1);
	tmp->num = num;
	tmp->next = NULL;
	if (*top != NULL )
		(*top)->next = tmp;
	else	
		*top = tmp;
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
	int	i;
	stack *stack_a;
	stack *head;

	stack_a = NULL;
	i = 0;
	push(pt[0], &stack_a);
	head = stack_a;
	while (i < size)
	{
		if (pt[i] != stack_a->num)
		{
			if (stack_a->next == NULL)
			{
				Sortpush(pt[i], &stack_a);
				i++;
				stack_a = head; 
			}
			else
				stack_a = stack_a->next;
		}
		else if (pt[i] == stack_a->num)
		{
			i++;
			stack_a = head;
		}
	}
	free(pt);
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
void	SortList(stack **stack)
{
	stack *tmp;
	stack *current;

	if (!*stack)
		exit(1);
	
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
