/*
* 5*5 grid
* from any position, hop 5 times
* form a 6-digit number, how many possible numbers?
* DFS
*/
 
#include<stdio.h>
#include<stdlib.h>

int grid[5][5];
int* set;
int count; /* length of array "set", not necessary */ 

void DFS(int i, int j, int k, int num)
{
	num = num * 10 + grid[i][j];
    if (k <= 4)
    {
        if (i > 0)
        {
            DFS(i-1, j, k+1, num);
        }
        if (i < 4)
        {
            DFS(i+1, j, k+1, num);
        }
        if (j > 0)
        {
            DFS(i, j-1, k+1, num);
        }
        if (j < 4)
        {
            DFS(i, j+1, k+1, num);
        }
	}
	else if (k == 5)
	{
		int in_array = 0;

		/* determine if num is in array "set" */
		for (int i=0; i<count; i++)
		{
			if (set[i] == num)
			{
				in_array = 1;
				break;
			}
		}
		if (in_array == 0)
		{
			count++;
			//printf("[%d] %d\n", count, num);
			set = (int*)realloc(set, count * sizeof(int)); /* alloc new memory space for array "set" */
			set[count-1] = num; /* store the value of num into array "set" */
		}
	}
}
 
void main()
{
	set = (int*)malloc(sizeof(int));
	count = 0;
	
    for (int i=0; i<5; i++)
    {
        for (int j=0; j<5; j++)
        {
			
            scanf("%d", &grid[i][j]);
        }
    }
    for (int i=0; i<5; i++)
    {
        for (int j=0; j<5; j++)
        {
            DFS(i, j, 0, 0);
        }
    }
    free(set);
    printf("%d\n", count);
}
