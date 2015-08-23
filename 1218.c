#include<stdio.h>
#include<string.h>

int main(){
	int m, n, i, j, count;
	int cell[100];
	
	scanf("%d", &m);
	while(m--){
		scanf("%d", &n);
		count = 0;
		memset(cell, 0, 100*sizeof(int));
		for(i=1; i<=n; i++){
			for(j=1; i*j<=n; j++){
				cell[i*j-1] = 1 - cell[i*j-1];
			}
		}
		for(i=1; i<=n; i++){
			if(cell[i-1] == 1)
				count++;
		}
		printf("%d\n", count);
	}
		
	return 0;
}
