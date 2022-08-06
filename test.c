#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int num;
	struct node *next;
}node;

typedef struct stack
{
	node *head;
	int size;
}stack;



int main()
{
    int ar[3] = {5,7,2};
    if ((ar[0] < ar[1]) && (ar[1] > ar[2]) && (ar[0] > ar[2]))
	{
		printf("-4\n");
	}
    else
        printf("ar[0]= %d < ar[1] = %d > ar[2] = %d\n",ar[0], ar[1], ar[2]);
}