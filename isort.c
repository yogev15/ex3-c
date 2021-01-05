#include <stdio.h>
#include <stdlib.h>

#define LENGTH 50

//shifting i elements of arr   
void shift_element(int* arr, int i)
{
    	for(int j = i ; j > 0; j--)
        	*(arr+j) = *(arr + j - 1);
}

//sorting arr by insertion sort
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

//print an array of numbers
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
    	
    	insertion_sort(arr,LENGTH);
    	printf("\n");
    	print_array(arr , LENGTH);
    	printf("\n");
   	free(arr);
    return 0;
}
