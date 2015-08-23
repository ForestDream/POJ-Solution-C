#include<stdio.h>
#include<string.h>
 
void main()
{
    char a[51];
    while (scanf("%s", a) != EOF && a[0] != '#')
    {
        int len = strlen(a);
        int i, j;
        char tmp;
        
        if(len == 1)
        {
            printf("No Successor\n");
            continue;
        }
        for (i=len-2; i>=0; i--)
        {
            if (a[i] < a[i+1])
            {
                for (j=len-1; j>i; j--)
                {
                    if (a[j] > a[i])
                    {
                        tmp = a[i];
                        a[i] = a[j];
                        a[j] = tmp;
						break;
                    }
                }
                for (j=i+1; j<(float)(len+i)/2; j++)
                {
                    tmp = a[j];
                    a[j] = a[len+i-j];
                    a[len+i-j] = tmp;
                }
                printf("%s\n", a);
                break;
            }
            if (i == 0)
            {
                printf("No Successor\n");
            }
        }
    }
}
