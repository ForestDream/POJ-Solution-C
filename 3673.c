#include<stdio.h>
#include<string.h>

int main(){
	int a, b, i, j, mtp;
	char s[10], t[10];
	
	scanf("%d%d", &a, &b);
	sprintf(s, "%d", a);
	sprintf(t, "%d", b);
	
 	mtp = 0;
	for(i=0; i<strlen(s); i++){
		for(j=0; j<strlen(t); j++){
			mtp += (s[i]-'0')*(t[j]-'0');
		}
	}
	printf("%d\n", mtp);
	return 0;
}
