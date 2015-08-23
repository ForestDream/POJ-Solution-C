#include<stdio.h>
#include<string.h>

int main(){
	int sum, i;
	char sr[255];
	
	while(gets(sr) && sr[0]!= '#'){
		sum = 0;
		for(i=0; i<strlen(sr); i++){
			if(sr[i]>='A' && sr[i]<='Z')
				sum += (i+1)*((int)sr[i] - 64);
		}
		printf("%d\n", sum);
	}
	return 0;
}
