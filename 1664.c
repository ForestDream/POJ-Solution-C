#include<stdio.h>

int f(int j, int m, int n){
	int i, ans;
	ans = 0;
	if(n == 1){
		ans = 1;
	}
	else{
	for(i=j; i<=m/n; i++){
		ans += f(i, m-i, n-1);
	
	}
	}
	// printf("f(%d, %d, %d)  %d\n", j, m, n, ans);
	return ans;
}

int main(){
	int t, m, n;
	int i, j;
	scanf("%d", &t);
	while(t-- > 0){
		scanf("%d%d", &m, &n);
		printf("%d\n", f(0, m, n));
	}
	return 0;
}