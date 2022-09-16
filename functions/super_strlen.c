/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   super_strlen.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhaddoum <zhaddoum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 21:24:40 by zhaddoum          #+#    #+#             */
/*   Updated: 2022/09/16 15:55:45 by zhaddoum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../actions.h"
#include "../functions.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

void	check_non_digit(char **str, int *k, int *i)
{
	int	y;

	y = 0;
	while (str[y])
	{
		if (str[y][0] == '\0')
		{
			write (2, "Error\n", 6);
			exit(1);
		}
		y++;
	}
	if (str[*i][*k] != ' ' && ft_isdigit(str[*i][*k]) == 0
	&& str[*i][*k] != '\0' && str[*i][*k] != '-' && str[*i][*k] != '+' )
	{
		write(2, "Error\n", 6);
		exit(1);
	}
}

void	sub_strlen(char **str, int *k, int *i, int *count)
{
	check_non_digit(str, k, i);
	if ((str[*i][*k] == ' ' && (*k) == 0)
		|| (str[*i][*k] == ' ' && str[*i][*k - 1] == ' '))
	{
		while (str[*i][*k] == ' ')
			(*k)++;
		return ;
	}	
	else if (str[*i][*k] == ' ' && ft_isdigit(str[*i][*k - 1]))
	{
		(*count)++;
		(*k)++;
	}
	else if (str[*i][*k] == '\0' && str[*i][*k - 1] != ' ')
		(*count)++;
}

int	super_strlen(char **str, int argc)
{
	int	i;
	int	count;
	int	k;

	i = 1;
	count = 0;
	k = 0;
	while (i < argc)
	{
		sub_strlen(str, &k, &i, &count);
		while (ft_isdigit(str[i][k]) || str[i][k] == '-' || str[i][k] == '+'
			|| str[i][k] == ' ')
		{
			k++;
			sub_strlen(str, &k, &i, &count);
		}
		if (str[i][k] != '\0')
			sub_strlen(str, &k, &i, &count);
		k = 0;
		i++;
	}
	return (count);
}
