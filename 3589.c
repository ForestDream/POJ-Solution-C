#include<stdio.h>

int main(){
	int t;
	char str1[5], str2[5];
	int a, b;
	
	scanf("%d", &t);
	while(t--){
		scanf("%s%s", str1, str2);
		a = b = 0;
		for(int i=0; i<4; i++){
			for(int j=0; j<4; j++){
				if(str1[i] == str2[j]){
					if(i == j)
						a++;
					else
						b++;
				}
			}
		}
		printf("%dA%dB\n", a, b);
	}
	return 0;
}
