#include<stdio.h>

int main(){
	int n, i, count;
	int s[141], t[141];
	
	s[0] = t[0] =1;
	for(i=2; i<=141; i++){
		s[i-1] = s[i-2] + i;
		t[i-1] = t[i-2] + i*i;
	}
	count = 0;
	while(scanf("%d", &n) != EOF && n && count<21){
		i=1;
		while(s[i-1]<=n)
			i++;
		printf("%d %d\n", n, t[i-2]+(n-s[i-2])*i);
		count++;
	}
	return 0;
}
