void    super_atoi(int **ar, char *ptr, int count)
{
    long			i;
    int				ret;
    int				sign;
    static int		k;
    int				j;

    i = 0;
    ret = 0;
    j = 0;
    sign = 1;
    if (!*ar)
        *ar = malloc(sizeof(int) * count);
    while(ptr[i])
    {
        if (ptr[i] == '-' || ptr[i] == '+')
        {
            if (ptr[i] == '-')
                sign *= -1;
            i++;
        }
        while (ptr[i] >= '0' && ptr[i] <= '9')
        {
            ret = ret * 10 + (ptr[i] - 48);
            i++;
        }
        if (AllSpaces(ptr[i]) == 0)
        {
            i++;
            ar[0][k] = ret * sign;
            sign = 1;
            ret = 0;
            k++;
        }
    
    }
    ar[0][k] = ret * sign;
    k++; 
}