#include<stdio.h>

int main(){
	int t, n, hf;
	
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		hf = n/2;
		printf("%d\n", hf*(hf-1)/2 + (n-hf)*(n-hf-1)/2);
	}
	return 0;
}
