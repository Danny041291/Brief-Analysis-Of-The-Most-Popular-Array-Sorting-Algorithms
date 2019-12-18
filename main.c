#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include "main.h"

int main(int argc, char * argv[])
{
	clock_t t;
	double time_taken;
	int array[8];
	
	array[0]=42;
	array[1]=38;
	array[2]=11;
	array[3]=75;
	array[4]=99;
	array[5]=23;
	array[6]=84;
	array[7]=67;
	
	printf("Array to order:\n");
	print_array(8,array);
	
	printf("Ordering phases:\n");
	t=clock();
	
	if(strcmp(argv[1],"insert")==0)
	{
		insert_sort(8,array);
	} else if(strcmp(argv[1],"select")==0) {
		select_sort(8,array);
	} else if(strcmp(argv[1],"bubble")==0) {
		bubble_sort(8,array);
	} else if(strcmp(argv[1],"merge")==0) {
		merge_sort(array,0,7);
	} else if(strcmp(argv[1],"quick")==0) {
		quick_sort(array,0,7);
	}
	
    t=clock()-t;
    time_taken=((double)t)/CLOCKS_PER_SEC;

	printf("Ordered array:\n");
	print_array(8,array);
	
	printf("The ordering process took %f seconds to execute.", time_taken);
	return 0;
}

void print_array(int arrc, int arrv[])
{
	int i;
	printf("[ ");
	for (i=0;i<arrc;i++)
		printf("%d ",arrv[i]);
	printf("]\n");
}

void copy_array(int arrv1[], int l1, int r1, int arrv2[], int l2, int r2)
{
	int i,j;
	for (i=l1,j=l2;i<=r1&&j<=r2;i++,j++) 
		arrv2[j]=arrv1[i];
}

void insert_sort(int arrc, int arrv[])
{
	int value,i,j;
	for(i=0;i<arrc;i++)
	{
		for(value=arrv[i],j=i-1;j>=0&&arrv[j]>value;j--)
			arrv[j+1]=arrv[j];
		if(j+1!=i)
			arrv[j+1]=value;
		print_array(8,arrv);
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
				index=j;
				min=arrv[index];
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
	int i,j,tmp;
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

void merge_sort(int arrv[], int left, int right)
{
	int arrc,middle;
	arrc=(right-left)+1;
	if (arrc>1)
	{
		middle=(left+right)/2;
		merge_sort(arrv,left,middle);
		merge_sort(arrv,middle+1,right);
		merge(arrc,arrv,left,middle,right);
		print_array(8,arrv);
	}
}

void merge(int arrc, int arrv[], int left, int middle, int right)
{
	int i,j,k;
	int * tmp;
	tmp=(int *)calloc(arrc, sizeof(int));
	for(i=left,j=middle+1,k=0;k<arrc;k++)
	{
		if((i<=middle&&arrv[i]<=arrv[j])||j>right) 
		{
			tmp[k]=arrv[i];
			i++;
		} else 
		{
			tmp[k]=arrv[j];
			j++;
		}
	}
	copy_array(tmp,0,arrc,arrv,left,right);
}

void quick_sort(int arrv[], int left, int right)
{
	int pivot,tmp,i,j;
	pivot=arrv[right];
	i=left;
	j=right-1;
	while(i<j)
	{
		while(arrv[i]<pivot)
			i++;
		while(arrv[j]>pivot)
			j--;
		if (i < j)
		{
			tmp = arrv[i];
			arrv[i] = arrv[j];
			arrv[j] = tmp;
			i++;
			j--;
		}
	}
	tmp = arrv[right];
	arrv[right] = arrv[i];
	arrv[i] = tmp;
	print_array(8,arrv);
	if (left < j)
		quick_sort(arrv,left,i-1);
	if (i < right)
		quick_sort(arrv,i+1,right);
}

