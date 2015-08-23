#include<stdio.h>
#include<math.h>

int  C, G, c[21], w[21], dp[21][15001];

int main(){
	int i, j, k;
	
	scanf("%d%d", &C, &G);
	for(i=1; i<=C; i++)
		scanf("%d", c+i);
	for(i=1; i<=G; i++)
		scanf("%d", w+i);
	
	/* DP */
	dp[0][7500] = 1;
	for(j=-7500; j<=7500; j++){
		printf("%d ", dp[0][j+7500]);
	}
	printf("\n");
	for(i=1; i<=G; i++){
		for(j=-7500; j<=7500; j++){
			if(dp[i-1][j+7500] != 0){
				for(k=1; k<=C; k++){
					dp[i][j+c[k]*w[i]+7500] += dp[i-1][j+7500];
				}
			}
		}
	}
	// printf("%d\n", dp[G][7500]);
	return 0;
}
