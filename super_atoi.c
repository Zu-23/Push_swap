/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhaddoum <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 10:16:37 by zhaddoum          #+#    #+#             */
/*   Updated: 2021/11/23 11:17:02 by zhaddoum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
int	AllSpaces(char c)
{
	if ((c == '\t') || (c == '\n') || (c == '\v')
		|| (c == '\f') || (c == ' ') || (c == '\r'))
		return (0)
	return (1);
}

int	super_atoi(int **ar, char *ptr)
{
	long		i;
	long		ret;
	int			sign;

	i = 0;
	sign = 1;
	ret = 0;
	while (AllSpaces(ptr[i]) == 0)
		i++;
	if (ptr[i] == '-' || ptr[i] == '+')
	{
		if (ptr[i] == '-')
			sign *= -1;
		i++;
	}
	while (ptr[i] >= '0' && ptr[i] <= '9' && ptr[i])
	{14
		ret = ret * 10 + (ptr[i] - 48);
		i++;
	}
	if (AllSpaces(ptr[i]) == 1)
	{
		printf("Error\n");
		exit(1);
	}
	*ar[k] = ret;
}
