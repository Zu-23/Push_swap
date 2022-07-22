/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhaddoum <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 11:47:06 by zhaddoum          #+#    #+#             */
/*   Updated: 2021/11/23 10:45:59 by zhaddoum         ###   ########.fr       */
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


int	super_strlen(char **str)
{
	int	i;
	int	count;
	int	k;

	i = 0;
	count = 0;
	k = 0;
	while (str[i])
	{
		while (ft_isdigit(str[i][k]) == 1 || str[i][k] == '-' || str[i][k] == '+')
		{
			k++;
			if (AllSpaces(str[i][k]) == 0)
			{
				count++;
				k++;
			}
		}
		if (str[i][k] != '\0')
		{
			printf("Error\n");
			exit(1);
		}
		i++;	
	}
	return (count);

}

int	super_atoi(int **ar, char *ptr, int count)
{
	long		i;
	long		ret;
	int			sign;

	i = 0;
	sign = 1;
	ret = 0;
	*ar = malloc(sizeof(int) * count);
	if (ptr[i] == '-' || ptr[i] == '+')
	{
		if (ptr[i] == '-')
			sign *= -1;
		i++;
	}
	while (ptr[i] >= '0' && ptr[i] <= '9' && ptr[i])
	{
		ret = ret * 10 + (ptr[i] - 48);
		i++;
	}
	*ar[k] = ret;
}
