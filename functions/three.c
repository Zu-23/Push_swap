/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhaddoum <zhaddoum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 16:57:46 by zhaddoum          #+#    #+#             */
/*   Updated: 2022/08/27 21:56:41 by zhaddoum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../actions.h"
#include "../functions.h"

void	three(t_stack *a)
{
	t_node	*tmp;
	int		ar[3];

	tmp = a -> head;
	ar[0] = tmp -> num;
	ar[1] = tmp -> next -> num;
	ar[2] = tmp -> next -> next -> num;
	if ((ar[0] > ar[1]) && (ar[1] < ar[2]) && (ar[0] < ar[2]))
		print_action("sa\n", a, NULL, 0);
	else if ((ar[0] > ar[1]) && (ar[1] > ar[2]) && (ar[0] > ar[2]))
	{
		print_action("sa\n", a, NULL, 0);
		print_action("rra\n", a, NULL, 0);
	}
	else if ((ar[0] > ar[1]) && (ar[1] < ar[2]) && (ar[0] > ar[2]))
		print_action("ra\n", a, NULL, 0);
	else if ((ar[0] < ar[1]) && (ar[1] > ar[2]) && (ar[0] < ar[2]))
	{
		print_action("sa\n", a, NULL, 0);
		print_action("ra\n", a, NULL, 0);
	}
	else if (ar[0] < ar[1] && ar[1] > ar[2] && ar[0] > ar[2])
		print_action("rra\n", a, NULL, 0);
}
