/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stackSize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhaddoum <zhaddoum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 16:58:11 by zhaddoum          #+#    #+#             */
/*   Updated: 2022/08/27 21:56:07 by zhaddoum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../actions.h"
#include "../functions.h"

int	stacksize(t_stack *x)
{
	t_node	*tmp;
	int		i;

	tmp = x -> head;
	i = 0;
	while (tmp)
	{
		tmp = tmp -> next;
		i++;
	}
	return (i);
}
