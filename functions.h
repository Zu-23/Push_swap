/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhaddoum <zhaddoum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 16:59:02 by zhaddoum          #+#    #+#             */
/*   Updated: 2022/08/27 22:45:31 by zhaddoum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H
# define FUNCTIONS_H

# include <unistd.h>
# include <stdlib.h>
# include "ft_printf/ft_printf.h"
# include "actions.h"

typedef struct super_atoi_var
{
	int		j;
	long	ret;
	int		sign;
}t_var;

void	checkdouble(long *pt, int size, t_stack *a);
void	sortpush(int num, t_stack *top);
void	go_to_index(t_stack *a, t_stack *b, int ndx, char c);
int		find_max_ndx(t_stack *a);
int		find_min_ndx(t_stack *a);
void	push(int num, t_stack *top);
int		empty(t_stack *stk);
void	delete(t_stack *stk);
void	three(t_stack *a);
void	five(t_stack *a, t_stack *b);
int		stacksize(t_stack *x);
void	max_min_int(long *ar, int size);

/*		find_first_min	*/
void	find_first_min(t_stack *a, t_stack *b);
int		distance_compare(int ndx, int size);
void	fill_min_ar(int *min_ar, int *ndx_ar, t_stack *b);
void	find_second_min(t_stack *b, int *min_ar, int *ndx_ar);
void	min_push(t_stack *a, t_stack *b, int *ndx_ar);

/*		hundred		*/
void	hundred(t_stack *a, t_stack *b, int n);
void	chunk(t_stack *a, t_stack *b, int pivot);

/*		list to array	*/
int		list_to_array(t_stack *a, int n);
int		lta_val_i(int size, int n);
void	arraysort(int *arr, int size);

/*		print action	*/
void	print_action(char *str, t_stack *x, t_stack *y, int chk);
int		ft_strcmp(char *s1, char *s2);
void	print_action_aux(char *str, char c, t_stack *x, t_stack *y);

/*		super atoi		*/
void	super_atoi(long **ar, char *ptr, int count);
void	allspaces(char *str, int *i);
void	after_int(char c, t_var *var, int *i);

/*		super strlen	*/
int		super_strlen(char **str, int argc);
int		ft_isdigit(int c);

#endif