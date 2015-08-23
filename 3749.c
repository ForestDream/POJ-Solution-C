#include<stdio.h>
#include<string.h>

char msg[201], s[6], e[4];
int len;

char dcd(char x){
	char y;
	if(x>=70 && x<=90)
		y = x - 5;
	else if(x>=65 && x<70)
		y = x - 5+26;
	else
		y = x;
	return y;
}

int main(){

	while(gets(s) && !strcmp(s, "START")){
		gets(msg);
		len = strlen(msg);
		for(int i=0; i<len; i++){
			msg[i] = dcd(msg[i]);
		}
		if(gets(e) && !strcmp(e, "END"))
			puts(msg);
	}
	return 0;
}
