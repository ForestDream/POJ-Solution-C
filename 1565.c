#include<stdio.h>
#include<string.h>
#include<math.h>

int main(){
	char skew[31];
	int n, len, i;
	
	while(scanf("%s", skew) != EOF && skew[0] != '0'){
		n = 0;
		len = strlen(skew);
		for(i=0; i<len; i++)
			n += (skew[i]-'0') * (int)(pow(2, len-i)-1);
		printf("%d\n", n);
	}
	return 0;
}
