#include<stdio.h>

int main(){
	int n, s[100], sum, min, max;
	
	while(scanf("%d", &n) && n){
		scanf("%d", &s[0]);
		sum = min = max = s[0];
		for(int i=1; i<n; i++){
			scanf("%d", &s[i]);
			sum += s[i];
			if(s[i] > max)
				max = s[i];
			if(s[i] < min)
				min = s[i];
		}
		printf("%d\n", (sum - min - max) / (n - 2));
	}
	return 0;
}
