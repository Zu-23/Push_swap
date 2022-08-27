/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   super_atoi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhaddoum <zhaddoum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 16:57:54 by zhaddoum          #+#    #+#             */
/*   Updated: 2022/08/27 22:47:15 by zhaddoum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../actions.h"
#include "../functions.h"

int	allspaces(char c)
{
	if ((c == '\t') || (c == '\n') || (c == '\v')
		|| (c == '\f') || (c == ' ') || (c == '\r'))
		return (0);
	return (1);
}

void	after_int(char c, t_var *var, int *i)
{
	if (c == '-' || c == '+')
	{
		if (c == '-')
		var -> sign *= -1;
		*i += 1;
	}
}

void	super_atoi(long **ar, char *ptr, int count)
{
	int				i;
	static int		k;
	t_var			var;

	var.ret = 0;
	var.j = 0;
	var.sign = 1;
	i = 0;
	if (!*ar)
		*ar = malloc(sizeof(long) * count);
	while (ptr[i])
	{
		after_int(ptr[i], &var, &i);
		while (ptr[i] >= '0' && ptr[i] <= '9')
			var.ret = var.ret * 10 + (ptr[i++] - 48);
		if (ptr[i] && allspaces(ptr[i++]) == 0)
		{
			ar[0][k++] = var.ret * var.sign;
			var.sign = 1;
			var.ret = 0;
		}
	}
	ar[0][k] = var.ret * var.sign;
	k++;
}
