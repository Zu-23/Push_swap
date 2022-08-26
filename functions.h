#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include<unistd.h>
#include<stdlib.h>
#include "ft_printf/ft_printf.h"
#include "actions.h"
typedef struct super_atoi_var
{
   int	j;
   long	ret;
   int	sign;
}var;

void	checkDouble(long *pt, int size, stack *a);
void	Sortpush(int num, stack *top);
void	go_to_index(stack *a, stack *b, int ndx, char c);
int	 	find_max_ndx(stack *a);
int		find_min_ndx(stack *a);
void	push(int num, stack *top);
int		Empty(stack *stk);
void	Delete(stack *stk);
void	three(stack *a);
void	five(stack *a, stack *b);
int		stackSize(stack *x);
void	max_min_int(long *ar, int size);

/*		find_first_min	*/
void	find_first_min(stack *a, stack *b);
int		distance_compare(int ndx, int size);
void	fill_min_ar(int *min_ar, int *ndx_ar, stack *b);
void	find_second_min(stack *b, int *min_ar, int *ndx_ar);
void	min_push(stack *a, stack *b, int *ndx_ar);

/*		hundred		*/
void	hundred(stack *a, stack *b, int n);
void	chunk(stack *a, stack *b, int pivot);

/*		list to array	*/
int		List_to_array(stack *a, int n);
int		lta_val_i(int size, int n);
void	arraySort(int *arr, int size);

/*		print action	*/
void	print_action(char *str, stack *x, stack *y);
int		ft_strcmp(char *s1, char *s2);
void	print_action_aux(char *str, char c, stack *x, stack *y);

/*		super atoi		*/
void	super_atoi(long **ar, char *ptr, int count);
int		AllSpaces(char c);
void	after_int(char c, var *var, int *i);

/*		super strlen	*/
int		super_strlen(char **str, int argc);
int		ft_isdigit(int c);



#endif