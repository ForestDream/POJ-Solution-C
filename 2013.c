#include<stdio.h>
#include<string.h>

int main(){
	int n, i, j, k, seq[15];
	char str[15][26], tmp[26];
	
	k = 0;
	while(scanf("%d", &n) != EOF && n){
		for(i=0; i<n; i++){
			scanf("%s", str[i]);
			strcpy(tmp, str[i]);
			for(j=i-1; j>=0, strlen(tmp) < strlen(str[j]); j--){
				strcpy(str[j+1], str[j]);
			}
			strcpy(str[j+1], tmp);
			if(i < (n+1)/2)
				seq[i] = i<<1;
			else
				seq[i] = 1+((n-1-i)<<1);
		}
		printf("SET %d\n", ++k);
		for(i=0; i<n; i++){
			printf("%s\n", str[seq[i]]);
		}
	}
	return 0;
}
