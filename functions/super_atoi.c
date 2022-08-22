#include "../actions.h"
#include "../functions.h"

// typedef struct super_atoi_var
// {
//    int	j;
//    int	ret;
//    int	sign;
// }var;

int	AllSpaces(char c)
{
	if ((c == '\t') || (c == '\n') || (c == '\v')
		|| (c == '\f') || (c == ' ') || (c == '\r'))
		return (0);
	return (1);
}

void     after_int(char c, var *var, int *i)
{
    if (c == '-' || c == '+')
    {
        if (c == '-')
            var -> sign *= -1;
        *i += 1;
    }
}

void    super_atoi(long **ar, char *ptr, int count)
{
    int				i;
    static int		k;
	var var;
 
	var.ret = 0;
	var.j = 0;
	var.sign = 1;
    i = 0;
    if (!*ar)
        *ar = malloc(sizeof(long) * count);
    while(ptr[i])
    {
        after_int(ptr[i], &var, &i);
        while (ptr[i] >= '0' && ptr[i] <= '9')//we changed i incr in ptr[i] it might cause prob
            var.ret = var.ret * 10 + (ptr[i++] - 48);
        if (ptr[i] && AllSpaces(ptr[i++]) == 0)//another doubt of prob ptr[i++]
        {
            ar[0][k++] = var.ret * var.sign; //potential prob k++
            var.sign = 1;
            var.ret = 0;
        }
    }
    ar[0][k] = var.ret * var.sign;
    k++; 
}