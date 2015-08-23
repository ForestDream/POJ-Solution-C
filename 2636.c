#include<stdio.h>

int main(){
	int n, k, i, ol[10], ols;
	
	scanf("%d", &n);
	while(n--){
		scanf("%d", &k);
		ols = 1;
		for(i=0; i<k; i++){
			scanf("%d", &ol[i]);
			ols += ol[i]-1;
		}
		printf("%d\n", ols);
	}
	return 0;
}
