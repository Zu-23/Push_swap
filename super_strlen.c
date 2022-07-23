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

typedef struct stack
{
	int num;
	struct stack *next;
}stack;

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}


// void	checkDouble(int *pt)
// {
// 	int	i;
// 	stack *stack_a;
// 	stack *beg;

// 	stack_a = NULL;
// 	i = 0;
// 	push(pt[0], &stack_a);
// 	beg = stack_a;
// 	while (pt[i])
// 	{
// 		if (pt[i] != stack_a->num)
// 		{
// 			if (stack_a->next == NULL)
// 			{
// 				push(pt[i], &stack_a);
// 				i++;
// 				stack_a = beg;
// 			}
// 			else
// 				stack_a = stack_a->next;
// 		}
// 		else if (pt[i] == stack_a->num)
// 		{
// 			i++;
// 			stack_a = beg;
// 		}
// 	}
// 	free(pt);

// }

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

int	ft_sign(char c)
{
	int	sign;

	sign = 1;
	if (c == '-' || c == '+')
		{
			if (c == '-')
				sign *= -1;
		}
	return (sign);
}

void	super_atoi(int **ar, char *ptr, int count)
{
	long		i;
	int			ret;
	int			sign;
	static int	k;
	int			j;

	i = 0;
	ret = 0;
	j = 0;
	k = 0;
	printf("value of k %d",k);
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
		while (ft_isdigit(ptr[i]) == 1)
		{
			ret = ret * 10 + (ptr[i] - 48);
			i++;
		}
		if (AllSpaces(ptr[i]) == 0)
		{
			i++;
			sign = 1;
			ar[0][k] = ret;
			ret = 0;
			k++;
			printf("val ar %d\n",ar[0][k]);
		}
	}
	ar[0][k] = ret;
	printf("val ar  %d\n",ar[0][k]);
	k++;
}


int main(int argc, char **argv)
{
	int	*int_array;
	int	size;
	int i = 1;

	int_array = NULL;
	size = super_strlen(argv,argc);
	while (i < argc)
	{
		super_atoi(&int_array, argv[i], size);
		i++;
	}
	
}
