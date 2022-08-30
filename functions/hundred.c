/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hundred.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhaddoum <zhaddoum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 16:28:03 by zhaddoum          #+#    #+#             */
/*   Updated: 2022/08/29 00:50:47 by zhaddoum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../actions.h"
#include "../functions.h"

void	chunk(t_stack *a, t_stack *b, int pivot)
{
	int		i;
	int		size;

	i = 0;
	size = stacksize(a);
	while (i < size)
	{
		if (a -> head -> num <= pivot)
			print_action("pb\n", a, b, 0);
		else if (i != size - 1)
			print_action("ra\n", a, b, 0);
		i++;
	}	
}

void	hundred(t_stack *a, t_stack *b, int n)
{
	int		pivot;

	while (a -> head)
	{
		pivot = list_to_array(a, n);
		chunk(a, b, pivot);
	}
	while (b -> head)
		find_first_min(a, b);
}
