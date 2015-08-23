#include<stdio.h>

int n, lgt[5][6], slt[6][6], cnt;

int main(){
	int i, j, p = 0;
	scanf("%d", &n);
	while(n--){
		for(i=0; i<5; i++){
			for(j=0; j<6; j++){
				scanf("%d", &lgt[i][j]);
			}
		}
		
		for(j=0; j<6; j++){
			slt[0][j] = 0;
			// if(j
			== 1 || j == 3 || j == 4)
				// slt[0][j] = 0;
			// else
				// slt[0][j] = 1;
		}
		
 		for(i=0; i<5; i++){
			for(j=0; j<6; j++){
				cnt = slt[i][j];
				if(j>0)
					cnt += slt[i][j-1];
				if(j<5)
					cnt += slt[i][j+1];
				
				if(cnt % 2 == 1){
					
					lgt[i][j] = 1 - lgt[i][j];
					
				}
				
				if(slt[i][j]){
					if(i > 0)
						lgt[i-1][j] = 1 - lgt[i-1][j];
					if(i < 4)
						lgt[i+1][j] = 1 - lgt[i+1][j];
				}
				slt[i+1][j] = lgt[i][j];
			}
		}
		printf("PUZZLE #%d\n", ++p);
		printf("lights\n");
		for(i=0; i<5; i++){
			for(j=0; j<6; j++){
				printf("%d ", lgt[i][j]);
			}
			printf("\n");
		}
		printf("buttons\n");
		for(i=0; i<5; i++){
			for(j=0; j<6; j++){
				printf("%d ", slt[i][j]);
			}
			printf("\n");
		}
	}
	return 0;
}