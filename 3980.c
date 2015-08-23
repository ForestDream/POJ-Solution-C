#include<stdio.h>

int mod(int n, int m){
	while(n >= m)
		n -= m;
	return n;
}

int main(){
	int a, b;
	
	while(scanf("%d%d", &a, &b) != EOF){
		printf("%d\n", mod(a, b));
	}
	return 0;
}
