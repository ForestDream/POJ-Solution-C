#include<stdio.h>

int main(){
	int n, i, j;
	int milk[9999];
	int tmp;
	scanf("%d", &n);
	for(i=0; i<n; i++){
		scanf("%d", &tmp);
		for(j=i-1; j>=0, tmp<milk[j]; j--){
			milk[j+1] = milk[j];
		}
		milk[j+1] = tmp;
	}
	printf("%d\n", milk[n/2]);
	return 0;
}