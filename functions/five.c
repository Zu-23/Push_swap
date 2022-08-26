/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   five.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhaddoum <zhaddoum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 15:58:46 by zhaddoum          #+#    #+#             */
/*   Updated: 2022/08/25 15:58:47 by zhaddoum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../actions.h"
#include "../functions.h"

void	five(stack *a, stack *b)
{
	int		min;
	int		max;

	if (stackSize(a) == 4)
	{
		min = find_min_ndx(a);
		go_to_index(a, b, min, 'a');
		three(a);
		print_action("pa", b, a);
	}
	else
	{
	min = find_min_ndx(a);
	go_to_index(a, b, min, 'a');
	max = find_max_ndx(a);
	go_to_index(a, b, max, 'a');
	three(a);
	print_action("pa", b, a);
	print_action("ra", a, NULL);
	print_action("pa", b, a);
	}
}	