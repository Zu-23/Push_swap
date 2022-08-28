/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhaddoum <zhaddoum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 01:15:20 by zhaddoum          #+#    #+#             */
/*   Updated: 2022/08/28 21:13:33 by zhaddoum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "actions.h"
#include "functions.h"
#include "get_next_line/get_next_line.h"

int	check_stack_norm(char *str, t_stack *a, t_stack *b, int i)
{
	if (str[i] == 'b')
	{
		if (str[i - 1] == 'p')
			print_action(str, a, b, 1);
		else
			print_action(str, b, a, 1);
		return (1);
	}
	return (0);
}

void	check_which_stack(char *str, t_stack *a, t_stack *b)
{
	int	i;
	int	hint;

	i = 0;
	hint = 0;
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
		else if (check_stack_norm(str, a, b, i))
			hint = 1;
		i++;
	}
	if (hint == 0)
		print_action(str, a, b, 1);
}

void	check_str(char *str)
{
	if (ft_strcmp(str, "ra\n") && ft_strcmp(str, "rb\n")
		&& ft_strcmp(str, "rr\n") && ft_strcmp(str, "sa\n")
		&& ft_strcmp(str, "sb\n")
		&& ft_strcmp(str, "ss\n") && ft_strcmp(str, "rra\n")
		&& ft_strcmp(str, "rrb\n")
		&& ft_strcmp(str, "rrr\n") && ft_strcmp(str, "pa\n")
		&& ft_strcmp(str, "pb\n"))
	{
		write(2, "Error\n", 6);
		exit(1);
	}
}

void	checker(t_stack *a, t_stack *b)
{
	char	*str;
	t_node	*tmp;

	str = get_next_line(0);
	while (str)
	{
		check_str(str);
		check_which_stack(str, a, b);
		free(str);
		str = get_next_line(0);
	}
	tmp = a -> head;
	while (tmp->next)
	{
		if (tmp->num > tmp->next->num)
		{
			ft_printf("KO\n");
			exit(1);
		}
		tmp = tmp->next;
	}
	ft_printf("OK\n");
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
	if (argc < 2)
		exit(1);
	while (++var[1] < argc)
		super_atoi(&array, argv[var[1]], var[0]);
	max_min_int(array, var[0]);
	checkdouble(array, var[0], &a);
	checker(&a, &b);
}
