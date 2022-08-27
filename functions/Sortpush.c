/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sortpush.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhaddoum <zhaddoum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 16:58:14 by zhaddoum          #+#    #+#             */
/*   Updated: 2022/08/27 21:55:58 by zhaddoum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../actions.h"
#include "../functions.h"

void	sortpush(int num, t_stack *top)
{
	t_node	*tmp;

	tmp = malloc(sizeof(t_node));
	if (!tmp)
		exit (1);
	tmp -> num = num;
	tmp -> next = NULL;
	if (top -> head != NULL )
		top -> head -> next = tmp;
	else
		top -> head = tmp;
}
