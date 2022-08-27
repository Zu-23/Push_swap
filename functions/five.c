/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   five.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhaddoum <zhaddoum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 15:58:46 by zhaddoum          #+#    #+#             */
/*   Updated: 2022/08/27 21:53:40 by zhaddoum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../actions.h"
#include "../functions.h"

void	five(t_stack *a, t_stack *b)
{
	int		min;
	int		max;

	if (stacksize(a) == 4)
	{
		min = find_min_ndx(a);
		go_to_index(a, b, min, 'a');
		three(a);
		print_action("pa\n", b, a, 0);
	}
	else
	{
		min = find_min_ndx(a);
		go_to_index(a, b, min, 'a');
		max = find_max_ndx(a);
		go_to_index(a, b, max, 'a');
		three(a);
		print_action("pa\n", b, a, 0);
		print_action("ra\n", a, NULL, 0);
		print_action("pa\n", b, a, 0);
	}
}	
