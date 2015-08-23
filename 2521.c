#include<stdio.h>
// #include<string.h>
// #include<math.h>

int main(){
	int M, N, P, C;
	
	while(scanf("%d%d%d%d", &M, &N, &P, &C) != EOF && (M||N||P||C)){
		printf("%d\n", M+P-N);
	}
	
	return 0;
}
