#include "../actions.h"
#include "../functions.h"

int	ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}

void	print_action_aux(char *str, char c, stack *x, stack *y)
{
	if (c == 'a')
	{
		if (ft_strcmp(str, "r") == 0)
			print_action("ra\n",x, y, 0);
		else if (ft_strcmp(str, "rr") == 0)
			print_action("rra\n", x, y, 0);
		else if (ft_strcmp(str, "p") == 0)
			print_action("pa\n", x, y, 0);
	}
	else if (c == 'b')
	{
		if (ft_strcmp(str, "r") == 0)
			print_action("rb\n",x, y, 0);
		else if (ft_strcmp(str, "rr") == 0)
			print_action("rrb\n", x, y, 0);
		else if (ft_strcmp(str, "p") == 0)
			print_action("pb\n", x, y, 0);
	}
}

void	print_action(char *str, stack *x, stack *y, int chk)
{
	if (ft_strcmp(str, "sa\n") == 0 || ft_strcmp(str, "sb\n") == 0)
		swap(x);
	else if (ft_strcmp(str, "ss\n") == 0)
		ss(x, y);
	else if (ft_strcmp(str, "ra\n") == 0 || ft_strcmp(str, "rb\n") == 0)
		rotate(x);
	else if (ft_strcmp(str, "rr\n") == 0)
		rr(x, y);
	else if (ft_strcmp(str, "rra\n") == 0 || ft_strcmp(str, "rrb\n") == 0)
		reverse(x);
	else if (ft_strcmp(str, "rrr\n") == 0)
		rrr(x, y);
	else if (ft_strcmp(str, "pa\n") == 0 || ft_strcmp(str, "pb\n") == 0)
		pushStack(x, y);
	if (chk == 0)
		ft_printf("%s",str);
}