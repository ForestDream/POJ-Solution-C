#include<stdio.h>

int main(){
	int L, M, s, e, i, j, n;
	
	while(scanf("%d%d", &L, &M) != EOF && (L || M)){
		n = L + 1;
		while(M--){
			scanf("%d%d", &s, &e);
			n -= (e-s)+1;
		}
		printf("%d\n", n);
	}
	
	return 0;
}
