#include<stdio.h>
#include<string.h>

char in[80], out[240];
int len;

int main(){
	
	while(gets(in) && in[0] != '#'){
		len = strlen(in);
		for(int i=0, j=0; i<len; i++){
			switch(in[i]){
				case ' ':
					out[j++] = '%';
					out[j++] = '2';
					out[j++] = '0';
					break;
				case '!':
					out[j++] = '%';
					out[j++] = '2';
					out[j++] = '1';
					break;
				case '$':
					out[j++] = '%';
					out[j++] = '2';
					out[j++] = '4';
					break;
				case '%':
					out[j++] = '%';
					out[j++] = '2';
					out[j++] = '5';
					break;
				case '(':
					out[j++] = '%';
					out[j++] = '2';
					out[j++] = '8';
					break;
				case ')':
					out[j++] = '%';
					out[j++] = '2';
					out[j++] = '9';
					break;
				case '*':
					out[j++] = '%';
					out[j++] = '2';
					out[j++] = 'a';
					break;
				default:
					out[j++] = in[i];
			}
			
		}
		puts(out);
		memset(out, 0, 240);
	}
	return 0;
}
