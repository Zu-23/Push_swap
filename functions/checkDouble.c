/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkDouble.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhaddoum <zhaddoum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 16:58:45 by zhaddoum          #+#    #+#             */
/*   Updated: 2022/08/27 21:50:59 by zhaddoum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../actions.h"
#include "../functions.h"

void	handle_error(long *pt, int *i, t_stack *a, t_node *top)
{
	if (pt[*i] == a -> head -> num)
	{
		if ((*i) != 0)
		{
			write(2, "Error\n", 6);
			exit(1);
		}
		(*i)++;
		a -> head = top;
	}
}

void	checkdouble(long *pt, int size, t_stack *a)
{
	int		i;
	t_node	*top;

	i = 0;
	push(pt[0], a);
	top = a -> head;
	while (i < size)
	{
		if (pt[i] != a -> head -> num)
		{
			if (a -> head -> next == NULL)
			{
				sortpush(pt[i], a);
				i++;
				a -> head = top;
			}
			else
				a -> head = a -> head -> next;
		}
		else
			handle_error(pt, &i, a, top);
	}
	free(pt);
}
