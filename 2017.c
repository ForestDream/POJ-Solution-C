#include<stdio.h>

int main(){
	int n, i, dist;
	int s[10], t[10];
	
	while(scanf("%d", &n) != EOF && n!=-1){
		dist = 0;
		for(i=0; i<n; i++){
			scanf("%d%d", &s[i], &t[i]);
			if(i == 0)
				dist += s[i]*t[i];
			else
				dist += s[i]*(t[i]-t[i-1]);
		}
		printf("%d miles\n", dist);
	}
	return 0;
}
