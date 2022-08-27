/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhaddoum <zhaddoum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 16:59:12 by zhaddoum          #+#    #+#             */
/*   Updated: 2022/08/27 21:47:49 by zhaddoum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ACTIONS_H
# define ACTIONS_H

typedef struct node
{
	int				num;
	struct node		*next;
}t_node;

typedef struct stack
{
	t_node	*head;
}t_stack;

void	pushstack(t_stack *stack_to_pull, t_stack *stack_to_push);
void	swap(t_stack *stk);
void	rotate(t_stack *stk);
void	reverse(t_stack *stk);
void	ss(t_stack *a, t_stack *b);
void	rr(t_stack *a, t_stack *b);
void	rrr(t_stack *a, t_stack *b);

#endif