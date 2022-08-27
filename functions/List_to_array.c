/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   List_to_array.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhaddoum <zhaddoum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 16:58:25 by zhaddoum          #+#    #+#             */
/*   Updated: 2022/08/27 21:54:29 by zhaddoum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../actions.h"
#include "../functions.h"

int	lta_val_i(int size, int n)
{
	int	i;

	i = 0;
	while (1)
	{
		if (i == size - 1)
			break ;
		else if (i == n - 1)
			break ;
		i++;
	}
	return (i);
}

void	arraysort(int *arr, int size)
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

int	list_to_array(t_stack *a, int n)
{
	int		*ar;
	int		i;
	int		size;
	t_node	*tmp;

	tmp = a -> head;
	size = stacksize(a);
	ar = malloc(sizeof(int) * size);
	i = 0;
	while (tmp)
	{
		ar[i++] = tmp -> num;
		tmp = tmp -> next;
	}
	arraysort(ar, size);
	i = lta_val_i(size, n);
	i = ar[i];
	free(ar);
	return (i);
}
