#include<stdio.h>

int n, od[30], sam[30], sum;

int main(){
	int i;
	while(scanf("%d", &n) && n){
		sum = 0;
		for(i=0; i<n; i++){
			scanf("%d", &od[i]);
			if(i > 0)
				sam[i] = sam[i-1] + od[i];
			else
				sam[i] = od[i];
			
			sum += od[i];
			// printf("%d  %d\n", sam[i], sum);
		}
		i = 0;
		while(2*sam[i] < sum)
			i++;
		if(2*sam[i] == sum)
			printf("Sam stops at position %d and Ella stops at position %d.\n", i+1, i+2);
		else
			printf("No equal partitioning.\n");
	}
	return 0;
}
