#include<stdio.h>
int main(){
	int m, n;
	char dna[100][51];
	int i, j, k;
	int s[100], seq[100];
	scanf("%d %d", &n, &m);
	getchar();
	for(i=0; i<m; i++){
		gets(dna[i]);
		s[i] = 0;
		for(j=0; j<n; j++){
			for(k=j+1; k<n; k++){
				if(dna[i][j] > dna[i][k])
					s[i] += 1;
			}
		}
		if(i == 0)
			seq[i] = i;
		else{
			for(j=i-1; j>=0 && s[seq[j]] > s[i]; j--){
					seq[j+1] = seq[j];
			}
			seq[j+1] = i;
		}
	}
	for(i=0; i<m; i++){
		puts(dna[seq[i]]);
	}
	return 0;
}