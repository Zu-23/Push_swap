/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhaddoum <zhaddoum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 01:15:20 by zhaddoum          #+#    #+#             */
/*   Updated: 2022/08/27 22:16:33 by zhaddoum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "actions.h"
#include "functions.h"
#include "get_next_line/get_next_line.h"

void	stack_status(t_stack *a)
{
	t_node	*tmp;

	tmp = a -> head;
	while (tmp->next)
	{
		if (tmp->num  > tmp->next->num)
		{
			ft_printf("KO\n");
			exit(1);
		}
		tmp = tmp->next;
	}
	ft_printf("OK\n");
}
void	check_which_stack(char *str, t_stack *a, t_stack *b)
{
	int i;
	int	hint;

	i = 0;
	hint = 0; // a variable to check if the str has 'a' or 'b'
	while (str[i])
	{
		if (str[i] == 'a')
		{
			if (str[i - 1] == 'p')
				print_action(str, b, a, 1);
			else
				print_action(str, a, b, 1);
			hint = 1;
		}
		else if (str[i] == 'b')
		{
			if (str[i - 1] == 'p')
				print_action(str, a, b, 1);
			else
				print_action(str, b, a, 1);
			hint = 1;
		}
		i++;
	}
	if (hint == 0)
		print_action(str, a, b, 1);
}
void	check_str(char *str)
{
	if (ft_strcmp(str, "ra\n") && ft_strcmp(str, "rb\n") &&
	ft_strcmp(str, "rr\n") && ft_strcmp(str, "sa\n") && ft_strcmp(str, "sb\n")
	&& ft_strcmp(str, "ss\n") && ft_strcmp(str, "rra\n") && ft_strcmp(str, "rrb\n")
	&& ft_strcmp(str, "rrr\n") && ft_strcmp(str, "pa\n") && ft_strcmp(str, "pb\n"))
	{
		write(2, "Error\n", 6);
		exit(1);
	} 
}
void    checker(t_stack *a, t_stack *b)
{
	char    *str; 

	str = get_next_line(0);
	while (str)
	{
		check_str(str);
		check_which_stack(str, a, b);
		free(str);
		str = get_next_line(0);
	}
	stack_status(a);
}
int main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;
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
	checkdouble(array, var[0], &a);
	checker(&a, &b);
}