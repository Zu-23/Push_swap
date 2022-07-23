#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include "header.h"



// The first argument should be at the top of the
// stack (be careful about the order).
int main(int argc, char **argv)
{
	int	*int_array;
	int	size;

	size = super_strlen(argv);
	super_atoi(&int_array, argv, size);
	checkDouble(&int_array,)
}

