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


int	super_strlen(char **str)
{
	int	i;
	int	count;
	int	k;

	i = 0;
	count = 0;
	k = 0;
	while (str[i])
	{
		while (ft_isdigit(str[i][k]) == 1 || str[i][k] == '-' || str[i][k] == '+')
		{
			k++;
			if (AllSpaces(str[i][k]) == 0)
			{
				count++;
				k++;
			}
		}
		if (str[i][k] != '\0')
		{
			printf("Error\n");
			exit(1);
		}
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

//over 25 lines and 5 variables need fixing
void	super_atoi(int **ar, char **ptr, int count)
{
	long		i;
	long		ret;
	int			sign;
	int			k;
	int			j;

	i = 0;
	ret = 0;
	k = -1;
	j = 0;
	*ar = malloc(sizeof(int) * count);
	while(ptr[++i])
	{
		if (ptr[i][j] == '-' || ptr[i][j] == '+')
		{
			if (ptr[i][j] == '-')
				sign *= -1;
			j++;
		}
		while (ft_isdigit(ptr[i][j]) == 1)
		{
			ret = ret * 10 + (ptr[i][j] - 48);
			j++;
		}
		if (AllSpaces(ptr[i][j]) == 0)
		{
			j++;
			sign = 1;
			*ar[++k] = ret;
		}
	}
}

int main(int argc, char **argv)
{
	int	*int_array;
	int	size;

	size = super_strlen(argv);
	super_atoi(&int_array, argv, size);
	int i = 0;
	while (i < size)
	{
		printf("%d\n",int_array[i]);
		i++;
	}
}
