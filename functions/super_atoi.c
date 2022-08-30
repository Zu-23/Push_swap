/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   super_atoi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhaddoum <zhaddoum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 16:57:54 by zhaddoum          #+#    #+#             */
/*   Updated: 2022/08/29 01:53:55 by zhaddoum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../actions.h"
#include "../functions.h"


void     after_int(char c, t_var *var, int *i)
{
    if (c == '-' || c == '+')
    {
        if (c == '-')
            var -> sign *= -1;
        *i += 1;
    }
}

void	allspaces(char *str, int *i)
{
	while (str[*i] == ' ')
		(*i)++;
}

void	var_declare(t_var *var)
{
	var->ret = 0;
	var->j = 0;
	var->sign = 1;
}

void    super_atoi(long **ar, char *ptr, int count)
{
    int				i;
    static int		k;
	t_var var;
 
	var_declare(&var);
    i = 0;
    if (!*ar)
        *ar = malloc(sizeof(int) * count);
    while(ptr[i])
    {
        after_int(ptr[i], &var, &i);
        while (ptr[i] >= '0' && ptr[i] <= '9')
            var.ret = var.ret * 10 + (ptr[i++] - 48);
        if (ptr[i] == ' ' && ft_isdigit(ptr[i - 1]))
        {
            ar[0][k++] = var.ret * var.sign;
            var.sign = 1;
            var.ret = 0;
        }
		allspaces(ptr, &i);
    }
	if (ft_isdigit(ptr[i - 1]))
    	ar[0][k++] = var.ret * var.sign;
}
