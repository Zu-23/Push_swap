#include<stdlib.h>
#include<unistd.h>
#include<stdio.h>
#include "header.h"



int main(int c, char **v)
{
	int pt[2][1];
	pt[0][0] = 123;
	pt[1][0] = 34;
	printf("%d\n",pt[0][0]);
}


