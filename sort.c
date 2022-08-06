int sort(int **ar, int size)
{
    int 	i;
    int 	j;
    int 	tmp;

    i = 0;
    j = 0;
    while (j < size - 1)
    {
        while (i < size - j - 1)
        {
            if (*ar[i] > *ar[i + 1])
            {
                tmp = *ar[i];
                *ar[i] = *ar[i + 1];
                *ar[i + 1] = tmp;
            }
            i++;
        }
        j++;
    }
	return (size / 2);
}