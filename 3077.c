#include<stdio.h>
#include<string.h>

char num[10];
int len;

int main(){
	int n;
	
	scanf("%d", &n);
	while(n--){
		scanf("%s", num);
		len = strlen(num);
		
		if(len > 1){
			for(int i=len-1; i>0; i--){
				if(num[i] >= '5')
					num[i-1] += 1;
				num[i] = '0';
			}
			if(num[0] == '5'+5){
				num[0] = '0';
				printf("1");
			}
		}
		puts(num);
	}
	return 0;
}
