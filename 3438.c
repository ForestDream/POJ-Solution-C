#include<stdio.h>

char num[1001];

int main(){
	int n, i, j, cnt;
	char dgt;
	scanf("%d", &n);
	while(n--){
		scanf("%s", num);
		dgt = num[0];
		cnt = 1;
		for(i=1; i<1001, num[i]!='\0'; i++){
			if(num[i] == num[i-1]){
				cnt++;
			}
			else{
				printf("%d%c", cnt, dgt);
				dgt = num[i];
				cnt = 1;
			}
		}
		printf("%d%c", cnt, dgt);
		printf("\n");
	}
	
	return 0;
}
