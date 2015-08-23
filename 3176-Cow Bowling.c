#include<stdio.h>
#include<stdlib.h>

int main(){
	int n, i, j;
	int **trg, **sum;
	int max_sum;
	
	scanf("%d", &n);
	trg = (int **)malloc(n*sizeof(int *));
	sum = (int **)malloc(n*sizeof(int *));
	
	for(i=0; i<n; i++){
		trg[i] = (int *)malloc((i+1)*sizeof(int));
		sum[i] = (int *)malloc((i+1)*sizeof(int));
		for(j=0; j<=i; j++){
			scanf("%d", &trg[i][j]);
			if(i == 0){
				sum[i][j] = trg[i][j];
			}else if(j == 0){
				sum[i][j] = sum[i-1][j] + trg[i][j];
			}else if(j == i){
				sum[i][j] = sum[i-1][j-1] + trg[i][j];
			}else{
				sum[i][j] = (sum[i-1][j-1]+trg[i][j])>(sum[i-1][j]+trg[i][j])?(sum[i-1][j-1]+trg[i][j]):(sum[i-1][j]+trg[i][j]);
			}
		}
	}

	max_sum = sum[n-1][0];
	for(j=1; j<n; j++){
		max_sum = sum[n-1][j]>max_sum?sum[n-1][j]:max_sum;
	}
	printf("%d\n", max_sum);
	free((void *)trg);
	free((void *)sum);
	return 0;
}
