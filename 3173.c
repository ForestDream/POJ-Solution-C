#include<stdio.h>

int ta[200][200];

int main(){
	int n, s, i, j;
	
	scanf("%d%d", &n, &s);
	for(j=0; j<n; j++){
		for(i=0; i<=j; i++){
			if(s == 10)
				s = 1;
			ta[i][j] = s++;
		}
	}
	for(i=0; i<n; i++){
		for(j=0; j<n; j++){
			if(ta[i][j])
				printf("%d ", ta[i][j]);
			else
				printf("  ", ta[i][j]);
		}
		printf("\n");
		
	}
	
	return 0;
}
