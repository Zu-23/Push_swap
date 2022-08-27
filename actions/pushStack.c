/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushStack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhaddoum <zhaddoum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 16:59:23 by zhaddoum          #+#    #+#             */
/*   Updated: 2022/08/27 21:57:23 by zhaddoum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../functions.h"
#include "../actions.h"

void	pushstack(t_stack *stack_to_pull, t_stack *stack_to_push)
{
	if (empty(stack_to_pull))
		return ;
	push(stack_to_pull -> head -> num, stack_to_push);
	delete(stack_to_pull);
}
