/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhaddoum <zhaddoum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 01:15:20 by zhaddoum          #+#    #+#             */
/*   Updated: 2022/08/26 02:00:14 by zhaddoum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "actions.h"
#include "functions.h"
#include "get_next_line/get_next_line.h"

void	stack_status(stack *a)
{
	node	*tmp;

	tmp = a -> head;
	while (tmp)
	{
		if (tmp -> num  > tmp -> next -> num)
		{
			ft_printf("KO\n");
			exit(1);
		}
		tmp = tmp -> next;
	}
	ft_printf("OK\n");
}
void	check_which_stack(char *str, stack *a, stack *b)
{
	int i;
	int	hint;

	i = 0;
	hint = 0; // a variable to check if the str has 'a' or 'b'
	while (str[i])
	{
		if (str[i] == 'a')
		{
			print_action(str, a, b);
			hint = 1;
		}
		else if (str[i] == 'b')
		{
			print_action(str, b, a);
			hint = 1;
		}
		i++;
	}
	if (hint == 0)
		print_action(str, a, b);
}
void	check_str(char *str)
{
	if (!ft_strcmp(str, "ra") || !ft_strcmp(str, "rb") ||
	!ft_strcmp(str, "rr") || !ft_strcmp(str, "sa") || !ft_strcmp(str, "sb")
	|| !ft_strcmp(str, "ss") || !ft_strcmp(str, "rra") || !ft_strcmp(str, "rrb")
	|| !ft_strcmp(str, "rrr") || !ft_strcmp(str, "pa") || !ft_strcmp(str, "pb"))
	{
		write(2, "Error\n", 6);
		exit(1);
	} 
}
void    checker(stack *a, stack *b)
{
	char    *str; 

	str = get_next_line(0);
	check_str(str);
	while (str)
	{
		check_which_stack(str, a, b);
		str = get_next_line(0);
		check_str(str);
	}
	stack_status(a);
}
int main(int argc, char **argv)
{
	stack	a;
	stack	b;
	int		var[2];
	long 	*array;

	a.head = NULL;
	b.head = NULL;
	array = NULL;
	var[0] = super_strlen(argv, argc); //size
	var[1] = 0; //int i
	if (argc < 2)
		exit(1);
	while (++var[1] < argc)
		super_atoi(&array,argv[var[1]], var[0]);
	max_min_int(array, var[0]);
	checkDouble(array, var[0], &a);
	checker(&a, &b);
}