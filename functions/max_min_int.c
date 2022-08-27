/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max_min_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhaddoum <zhaddoum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 01:20:32 by zhaddoum          #+#    #+#             */
/*   Updated: 2022/08/27 19:00:38 by zhaddoum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../actions.h"
#include "../functions.h"

void	max_min_int(long *ar, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (ar[i] > 2147483647 || ar[i] < -2147483648)
		{
			write(2, "Error\n", 6);
			exit(1);
		}
		i++;
	}
}
