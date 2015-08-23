#include<stdio.h>

int main(){
	int n, x, lay, dst, tmp;
	
	scanf("%d", &n);
	while(n--){
		scanf("%d", &x);
		lay = 1, dst = 1, tmp = x;
		
		while(tmp%2 == 0){
			lay++;
			tmp /= 2;
			dst *= 2;
		}
		printf("%d %d\n", x-dst+1, x+dst-1);
	}
	return 0;
}
