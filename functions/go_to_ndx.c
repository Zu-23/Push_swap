/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   go_to_ndx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhaddoum <zhaddoum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 15:58:42 by zhaddoum          #+#    #+#             */
/*   Updated: 2022/08/27 21:53:51 by zhaddoum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../actions.h"
#include "../functions.h"

void	go_to_index(t_stack *a, t_stack *b, int ndx, char c)
{
	int		i;
	int		size;

	i = 0;
	size = stacksize(a);
	while (1)
	{
		if (ndx <= size / 2)
		{
			if (i == ndx)
				break ;
			print_action_aux("r", c, a, b);
			i++;
		}
		else if (ndx > size / 2)
		{
			if (size == ndx)
				break ;
			print_action_aux("rr", c, a, b);
			size--;
		}
	}
	if (c == 'a')
		print_action_aux("p", 'b', a, b);
	else if (c == 'b')
		print_action_aux("p", 'a', a, b);
}