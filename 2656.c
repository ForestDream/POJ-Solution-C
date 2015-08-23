#include<stdio.h>

int main(){
	int n, i, ans;
	int s[7], as[7];
	
	while(scanf("%d", &n) && n){
		ans = 0;
		for(i=1; i<=n; i++){
			scanf("%d%d", &s[i], &as[i]);
			if(s[i] + as[i] > 8){
				if(ans == 0)
					ans = i;
				else
					ans = s[i]+as[i]>s[ans]+as[ans]?i:ans;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
