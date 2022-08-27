/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhaddoum <zhaddoum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 01:15:26 by zhaddoum          #+#    #+#             */
/*   Updated: 2022/08/27 22:46:44 by zhaddoum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "actions.h"
#include "functions.h"

void	push_swap(t_stack *a, t_stack *b)
{
	int	size;

	size = stacksize(a);
	if (size == 2)
	{
		if (a -> head -> num > a -> head -> next -> num)
			print_action("sa\n", a, b, 0);
	}
	else if (size == 3)
		three(a);
	else if (size > 3 && size <= 5)
		five(a, b);
	else if (size > 5 && size < 500)
		hundred(a, b, size / 7);
	else if (size >= 500)
		hundred(a, b, size / 16);
}

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;
	int		var[2];
	long	*array;

	a.head = NULL;
	b.head = NULL;
	array = NULL;
	var[0] = super_strlen(argv, argc);
	var[1] = 0;
	while (++var[1] < argc)
		super_atoi(&array, argv[var[1]], var[0]);
	max_min_int(array, var[0]);
	checkdouble(array, var[0], &a);
	push_swap(&a, &b);
}
