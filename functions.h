#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include<unistd.h>
#include<stdio.h> //delete later
#include<stdlib.h>
void    super_atoi(int **ar, char *ptr, int count);
int     super_strlen(char **str, int argc);
int     ft_isdigit(int c);
void    checkDouble(int *pt, int size);
void    Sortpush(int num, stack *top);
int     sort(int **ar, int size);
void	sortstack_a(stack *a, stack *b);
void	go_to_index(stack *a, stack *b, int ndx);
int     find_max_ndx(stack *a);
void	push(int num, stack *top);
int		Empty(stack *stk);
void	Delete(stack *stk);

#endif