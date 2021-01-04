#include <stdio.h>
#include <stdlib.h>

#define LENGTH 50

void shift_element(int* arr, int i)
{
    	for(int j = i ; j > 0; j--)
        	*(arr+j) = *(arr + j - 1);
}

void insertion_sort(int* arr , int len)
{
    	int temp = -1 ,i,j;
    	for(i = 1; i < len ; i++)
    	{
        	temp = *(arr+i);
        	j = i-1;
        	while(j >= 0 && *(arr+j) > temp)
            		j--;
        	shift_element((arr + j )  , i-j);
        	*(arr+j+1) = temp;
    	}
}

void print_array(int* arr, int n)
{
    	int i;
    	for (i = 0; i < n-1 ; i++) 
		printf("%d,", *(arr + i));
    	printf("%d\n", *(arr + i));
}

int main()
{
    	int *arr = (int *) calloc(LENGTH,sizeof(int *));
    	for(int i = 0 ; i < LENGTH; i++)
    		scanf("%d", arr+i);  
    	printf("before sorting:\n");
    	print_array(arr , LENGTH);
    	insertion_sort(arr,LENGTH);
    	printf("\nbefore sorting\n");
    	print_array(arr , LENGTH);
   	free(arr);
    return 0;
}
