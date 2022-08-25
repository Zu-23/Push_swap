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
			print_action("ra",x, y);
		else if (ft_strcmp(str, "rr") == 0)
			print_action("rra", x, y);
		else if (ft_strcmp(str, "p") == 0)
			print_action("pa", x, y);
	}
	else if (c == 'b')
	{
		if (ft_strcmp(str, "r") == 0)
			print_action("rb",x, y);
		else if (ft_strcmp(str, "rr") == 0)
			print_action("rrb", x, y);
		else if (ft_strcmp(str, "p") == 0)
			print_action("pb", x, y);
	}
}

void	print_action(char *str, stack *x, stack *y)
{
	printf("%s\n",str);
	if (ft_strcmp(str, "sa") == 0 || ft_strcmp(str, "sb") == 0)
		swap(x);
	else if (ft_strcmp(str, "ss") == 0)
		ss(x, y);
	else if (ft_strcmp(str, "ra") == 0 || ft_strcmp(str, "rb") == 0)
		rotate(x);
	else if (ft_strcmp(str, "rr") == 0)
		rr(x, y);
	else if (ft_strcmp(str, "rra") == 0 || ft_strcmp(str, "rrb") == 0)
		reverse(x);
	else if (ft_strcmp(str, "rrr") == 0)
		rrr(x, y);
	else if (ft_strcmp(str, "pa") == 0 || ft_strcmp(str, "pb") == 0)
		pushStack(x, y);
}