#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
	int N, i, j, len;
	char str[201];
	char **rec;
	
	while(scanf("%d", &N) != EOF && N){ 
		scanf("%s", str);
		len = strlen(str);
		rec = (char **)malloc((len/N)*sizeof(char *));
		
		for(i=0; i<len/N; i++){
			rec[i] = (char *)malloc(N*sizeof(char));
			for(j=0; j<N; j++){
				if(i%2 == 0)
					rec[i][j] = str[i*N+j];
				else
					rec[i][N-1-j] = str[i*N+j];
			}
		}
		for(j=0; j<N; j++){
			for(i=0; i<len/N; i++){
				printf("%c", rec[i][j]);
			}
		}
		printf("\n");
	}
	return 0;
}
