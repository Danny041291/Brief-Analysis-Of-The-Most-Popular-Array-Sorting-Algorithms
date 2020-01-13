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
	
	if(strcmp(argv[1],"insertion")==0)
	{
		insertion_sort(8,array);
	} else if(strcmp(argv[1],"selection")==0) {
		selection_sort(8,array);
	} else if(strcmp(argv[1],"bubble")==0) {
		bubble_sort(8,array);
	} else if(strcmp(argv[1],"merge")==0) {
		merge_sort(array,0,7);
	} else if(strcmp(argv[1],"quick")==0) {
		quick_sort(array,0,7);
	} else if(strcmp(argv[1],"heap")==0) {
		heap_sort(array,0,7);
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

void insertion_sort(int arrc, int arrv[])
{
	int value,i,j;
	/* 
		The array is traversed starting from the second item.
	*/
	for(i=1;i<arrc;i++)
	{
		/* 
			The current item is stored into a new variable.
			His position it's dragged back until his value 
			is lower than the previous one.
		*/
		for(value=arrv[i],j=i-1;j>=0&&arrv[j]>value;j--)
			arrv[j+1]=arrv[j];
		/* 
			The last reached item is replaced with the stored one.
		*/
		if(j+1!=i)
			arrv[j+1]=value;
		print_array(8,arrv);
	}
}

void selection_sort(int arrc, int arrv[])
{
	int i,j,min,index;
	/* 
		The array is traversed starting from the first item.
	*/
	for(i=0;i<arrc;i++)
	{
		/* 
			The current item is stored as the lowest one.
		*/
		for(min=arrv[i],index=i,j=i+1;j<arrc;j++)
		{
			/*
				If any item is lower of the minimum one, the minimum 
				is updated with it.
			*/
			if(arrv[j]<min)
			{
				index=j;
				min=arrv[index];
			}
		}
		/*
			The current item is swapped with the lowest one.
		*/
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
	/* 
		Starting from the first item, the entire array is traversed 
		until the ending of the array has not been reached or no more
		interchanges between items are needed.
	*/
	for(swap=True,i=0;i<arrc&&swap==True;i++)
	{
		/* 
			Starting from the ending, the entire array is traversed 
			until the current item has not been reached.
		*/
		for(swap=False,j=arrc;j>i;j--)
		{
			/* 
				If the previous item value is greater then the 
				current one, a swap happens.
			*/
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
	/* 
		A split of the array is performed in the middle 
		if the length is greater then 1.
	*/
	if (arrc>1)
	{
		middle=(left+right)/2;
		/* 
			The left and the rigth sub-arrays are recursively 
			analized.
		*/
		merge_sort(arrv,left,middle);
		merge_sort(arrv,middle+1,right);
		/*
			When no more splits are available the items are 
			merged.
		*/
		merge(arrc,arrv,left,middle,right);
		print_array(8,arrv);
	}
}

void merge(int arrc, int arrv[], int left, int middle, int right)
{
	int i,j,k;
	int * tmp
	/* 
		An auxiliary array of the same length is needed.
	*/
	tmp=(int *)calloc(arrc, sizeof(int));
	/* 
		The left and the right sub-arrays are analized
		at the same time.
	*/
	for(i=left,j=middle+1,k=0;k<arrc;k++)
	{
		/*
			The items of both arrays are put into the auxiliary one
			in a ordered way.
		*/
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
	/*
		The auxiliary array is copied into the original one.
	*/
	copy_array(tmp,0,arrc,arrv,left,right);
}

void quick_sort(int arrv[], int left, int right)
{
	int pivot,tmp,i,j;
	/* 
		The right most item is marked as pivot.
	*/
	pivot=arrv[right];
	i=left;
	j=right-1;
	/*
		The items lower than the pivot are swapped with
		the greater ones.
	*/
	while(i<j)
	{
		while(arrv[i]<pivot)
			i++;
		while(arrv[j]>pivot)
			j--;
		if (i<j)
		{
			tmp= arrv[i];
			arrv[i]= arrv[j];
			arrv[j]= tmp;
			i++;
			j--;
		}
	}
	/*
		The first item greater than the pivot is swapped 
		with it.
	*/
	tmp=arrv[right];
	arrv[right]=arrv[i];
	arrv[i]=tmp;
	print_array(8,arrv);
	/*
		The array is splitted in two parts and the sub-arrays 
		are analyzed in a recursive way. 
	*/
	if (left<j)
		quick_sort(arrv,left,i-1);
	if (i<right)
		quick_sort(arrv,i+1,right);
}

void heap_sort(int arrv[], int left, int right)
{
	int i,tmp;
	for(i=right;i>=0;i--)
	{
		heapify(arrv, left, i);
		tmp = arrv[i];
		arrv[i] = arrv[left];
		arrv[left] = tmp;
		print_array(8,arrv);
	}
}

void heapify(int arrv[], int left, int right)
{
	int i,j,z,tmp;
	boolean swap=True;
	while(swap==True)
	{
		swap=False;
		for(i=0;i<right/2;i++)
		{
			for(z=0,j=1+(i*2);z<=1&&j<=right;z++,j++)
			{
				if(arrv[i]<arrv[j])
				{
					tmp = arrv[i];
					arrv[i] = arrv[j];
					arrv[j] = tmp;
					swap=True;
				}
			}
		}
	}
}