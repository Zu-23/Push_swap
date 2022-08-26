/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hundred.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhaddoum <zhaddoum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 16:28:03 by zhaddoum          #+#    #+#             */
/*   Updated: 2022/08/26 19:13:09 by zhaddoum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../actions.h"
#include "../functions.h"

void	chunk(stack *a, stack *b, int pivot)
{
	int		i;
	int		size;

	i = 0;
	size = stackSize(a);
	while (i < size)
	{
		if (a -> head -> num <= pivot)
			print_action("pb\n", a, b, 0);
		else if (i != size - 1) //to not rotate the last element which has been already checked
			print_action("ra\n", a, b, 0);
		i++;
	}	
}

void	hundred(stack *a, stack *b, int n) 
{
	int		pivot;

	while (a -> head)
	{ 
		pivot = List_to_array(a, n);
		chunk(a, b, pivot);
	}
	while (b -> head)
		find_first_min(a, b);
	node *tmp = a ->head;
	while (tmp)
	{
		ft_printf("%d\n",tmp->num);
		tmp = tmp->next;
	}
}