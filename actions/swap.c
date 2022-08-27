/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhaddoum <zhaddoum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 16:59:40 by zhaddoum          #+#    #+#             */
/*   Updated: 2022/08/27 21:58:42 by zhaddoum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../actions.h"
#include "../functions.h"

void	swap(t_stack *stk)
{
	int	var;

	if (empty(stk) == 1 || stk -> head -> next == NULL)
		return ;
	var = stk -> head -> num;
	stk-> head -> num = stk -> head -> next -> num;
	stk -> head -> next -> num = var;
}
