#include<stdio.h>

int main(){
	int t, n, i, j;
	int p[20], w[20], depth[20];
	
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(i=0; i<n; i++){ 
			scanf("%d", p+i); 
			if(i == 0){
				depth[i] = p[i] - 1;
				w[i] = 1;
			}
			else{
				depth[i] = depth[i-1] + p[i] - p[i-1] - 1;
				j = i - 1;
				w[i] = 1;
				while(depth[j]>depth[i] && j>=0){
					j--;
					w[i]++;
				}
			}
			printf("%d ", w[i]);
		}
		printf("\n");
	}
	return 0;
}
