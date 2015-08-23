#include<stdio.h>
#include<string.h>
#include<math.h>

int main(){
	int T, i, j, colon, H, M;
	char t[30][6];
	
	scanf("%d", &T);
	for(i=0; i<T; i++){
		scanf("%s", t[i]);
		for(j=0; j<5; j++)
			if(t[i][j] == ':')
				colon = j;
		H = M = 0;
		for(j=strlen(t[i])-1; j>colon; j--)
			M += (t[i][j]-'0')*pow(10, strlen(t[i])-1-j);
		for(j=colon-1; j>=0; j--)
			H += (t[i][j]-'0')*pow(10, colon-1-j);
		if(M != 0)
			printf("%d\n", 0);
		else if(H<=12 && H>=1)
			printf("%d\n", H+12);
		else
			printf("%d\n", (H+12)%24);
	}
			
	return 0;
}
