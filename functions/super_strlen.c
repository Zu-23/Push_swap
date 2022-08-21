#include "../actions.h"
#include "../functions.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

int	super_strlen(char **str, int argc)
{
	int	i;
	int	count;
	int	k;

	i = 1;
	count = 0;
	k = 0;
	while (i < argc)
	{
		while (ft_isdigit(str[i][k]) == 1 || str[i][k] == '-')
		{
			k++;
			if (str[i][k] == ' ')
			{
				count++;
				k++;
			}
			else if (str[i][k] == '\0')
				count++;
		}
		if (str[i][k] != '\0')
		{
			printf("Error\n");
			exit(1);
		}
		k = 0;
		i++;	
	}
	return (count);
}
