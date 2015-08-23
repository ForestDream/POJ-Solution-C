#include<stdio.h>

int main(){
	int N, pn[8001], seq[8001], i, j;
	
	scanf("%d", &N);
	pn[1] = 0;
	seq[1] = 1;
	for(i=2; i<=N; i++){
		scanf("%d", pn+i);
		for(j=i; j>1, j>pn[i]+1; j--){
			seq[j] = seq[j-1];
		}
		seq[j] = i;
	}
	for(i=1; i<=N; i++){
		for(j=1; j<=N; j++){
			if(seq[j] == i)
				printf("%d\n", j);
		}
	}
	return 0;
}
