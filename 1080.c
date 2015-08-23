//借鉴开开甲的思路
#include<stdio.h>
#include<stdlib.h>

int score[5][5] = {
	{5, -1, -2, -1, -3},
	{-1, 5, -3, -2, -4},
	{-2, -3, 5, -2, -2},
	{-1, -2, -2, 5, -1},
	{-3, -4, -2, -1, 10}
};

int max(int a, int b, int c){
	int tmp;
	tmp = a>b?a:b;
	return c>tmp?c:tmp;
}

int index(char a){
	int t;
	switch(a){ 
		case 'A': t = 0; break;
		case 'C': t = 1; break;
		case 'G': t = 2; break;
		case 'T': t = 3; break;
		default: t = 4; break;
	}
	return t;
}

int main(){
	
	int m, n, t, i, j;
	char *a, *b;
	int **sml;

	scanf("%d", &t);
	
	while(t-- > 0){
		if(scanf("%d", &m) && 0<m<=100)
			(a = (char *)malloc(m*sizeof(char)));
		scanf("%s", a);
		if(scanf("%d", &n) && 0<n<=100)
			(b = (char *)malloc(n*sizeof(char)));
		scanf("%s", b);
		
		sml = (int **)malloc((m+1)*sizeof(int *));
		for(i=0; i<=m; i++){
			sml[i] = (int *)malloc((n+1)*sizeof(int));
		}
		
		sml[0][0] = 0;
		for(i = 1 ; i <= m ; i++)
			sml[i][0] = sml[i-1][0] + score[index(a[i-1])][index('-')];
		 
		for(i = 1 ; i <= n ; i++)
			sml[0][i] = sml[0][i-1] + score[index('-')][index(b[i-1])];    
		
		for(i = 1 ; i <= m ; i++)
			for(j = 1 ; j <= n ; j++)
			{
				sml[i][j] =max(sml[i-1][j-1]+score[index(a[i-1])][index(b[j-1])],
					sml[i-1][j]+score[index(a[i-1])][index('-')],
					sml[i][j-1]+score[index('-')][index(b[j-1])]);     
			}
		
		printf("%d\n",sml[m][n]);
		
		free(a);
		free(b);
		free(sml);
	}
	return 0;
}