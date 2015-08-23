#include<stdio.h>
#include<math.h>
#define N 50010

int bigger(int a, int b){
	if(a>b){return a;}
	else{return b;}
}

int smaller(int a, int b){
	if(a>b){return b;}
	else{return a;}
}

int main(){
	int n, q, height[N];
	int max[N][20], min[N][20];
	int start, end;
	int i, j, log2_n;
	
	scanf("%d%d", &n, &q);
 	log2_n = (int)(log((double)(n))/log(2.0));
	
	for(i=0; i<n; i++){
		scanf("%d", &height[i]);

		max[i][0] = height[i];
		min[i][0] = height[i];
	}
	for(j=1; j<=log2_n; j++){
		for(i=0; i+(1<<j)-1<n; i++){
			max[i][j] = bigger(max[i][j-1], max[i+(1<<(j-1))][j-1]);
			min[i][j] = smaller(min[i][j-1], min[i+(1<<(j-1))][j-1]);
			// printf("[i]%d  [j]%d  [max]%d [min]%d\n", i, j, max[i][j], min[i][j]);
		}
	}
	
 	while(q--){
		scanf("%d%d", &start, &end);
		j = (int)(log((double)(end-start+1))/log(2.0));
		printf("%d\n", bigger(max[start-1][j], max[end-(1<<j)][j]) - smaller(min[start-1][j], min[end-(1<<j)][j]));
	}
	return 0;
}
