#include <stdio.h>
#include <time.h>
#include <string.h>

#include "main.h"

int main(int argc, char * argv[])
{
	clock_t t;
	int array[8];
	array[0] = 42;
	array[1] = 38;
	array[2] = 11;
	array[3] = 75;
	array[4] = 99;
	array[5] = 23;
	array[6] = 84;
	array[7] = 67;
	
	printf("Array to order:\n");
	print_array(8, array);
	
	printf("Ordering phases:\n");
	t = clock();
	
	if(strcmp(argv[1], "insert")==0)
	{
		insert_sort(8, array);
	} else if(strcmp(argv[1], "select")==0) {
		select_sort(8, array);
	} else if(strcmp(argv[1], "bubble")==0) {
		bubble_sort(8, array);
	}
	
    t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC;

	printf("Ordered array:\n");
	print_array(8, array);
	
	printf("The ordering process took %f seconds to execute.", time_taken);
	return 0;
}

void print_array(int arrc, int arrv[])
{
	int i;
	printf("[ ");
	for (i=0;i<arrc;i++)
		printf("%d ", arrv[i]);
	printf("]\n");
}

void insert_sort(int arrc, int arrv[])
{
	int value,i,j;
	for(i=0;i<arrc;i++)
	{
		for(value=arrv[i],j=i-1;j>=0 && arrv[j]>value;j--)
			arrv[j+1]=arrv[j];
		if(j+1!=i)
			arrv[j+1]=value;
		print_array(8, arrv);
	}
}

void select_sort(int arrc, int arrv[])
{
	int i,j,min,index;
	for(i=0;i<arrc-1;i++)
	{
		for(min=arrv[i],index=i,j=i+1;j<arrc;j++)
		{
			if(arrv[j]<min)
			{
				index = j;
				min = arrv[index];
			}
		}
		if(index!=i) 
		{
			arrv[index]=arrv[i];
			arrv[i]=min;
		}
		print_array(8, arrv);
	}
}

void bubble_sort(int arrc, int arrv[])
{
	boolean swap;
	int i, j, tmp;
	for(swap=True,i=0;i<arrc-1&&swap==True;i++)
	{
		for(swap=False,j=arrc-1;j>=i;j--)
		{
			if (arrv[j]<arrv[j-1])
			{
				tmp=arrv[j-1];
				arrv[j-1]=arrv[j];
				arrv[j]=tmp;
				if(swap==False)
					swap=True;
			}
		}
		if(swap==True)
			print_array(8, arrv);
	}
}