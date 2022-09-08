/* Q2: Implementing Insertion Sort Algorithm*/

#include<stdio.h>

void main()
{
        int A[20], N, temp, i, j;

        printf("\n ENTER THE MAXIMUM NUMBER OF ELEMENT:\n");
        scanf("%d", &N);
        printf("\n ENTER THE ELEMENTS OF THE ARRAY:\n");
        for(i=0; i<N; i++)
        {
         scanf("\n%d", &A[i]);
        }
        //logic for insertion sort
	for(i=1; i<N; i++)
        {
                temp = A[i];
                j = i-1;
                while(temp < A[j] && j>=0)
                {
                   A[j+1] = A[j];
                   j = j-1;
                }
                A[j+1] = temp;
        }
        printf("\nTHE ASCENDING ORDER BY INSERTION SORT IS...:\n");
        for(i=0; i<N; i++)
        printf("%d\n", A[i]);
}

