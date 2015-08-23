#include<stdio.h>
#include<stdlib.h>

int comp(const void*a,const void*b)
{
return *(int*)a-*(int*)b;
}

int main(){
	int k, i, num[101], sum;
	
	scanf("%d", &k);
	for(i=0; i<k; i++){
		scanf("%d", num+i);
	}
	qsort(num, k, sizeof(int), comp);

	sum = 0;
	for(i=0; i<=k/2; i++){
		sum += (num[i]/2) + 1;
	}
	printf("%d\n", sum);
	return 0;
}
