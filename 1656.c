#include<stdio.h>
#include<string.h>

int board[101][101];

int main(){
	int t, x, y, l, i, j, count;
	char cmd[6];
	
	scanf("%d", &t);
	while(t--){
		scanf("%s%d%d%d", cmd, &x, &y, &l);
		if(!strcmp(cmd, "BLACK")){
			for(i=x; i<x+l; i++){
				for(j=y; j<y+l; j++){
					board[i][j] = 1;
				}
			}
		}
		else if(!strcmp(cmd, "WHITE")){
			for(i=x; i<x+l; i++){
				for(j=y; j<y+l; j++){
					board[i][j] = 0;
				}
			}
		}
		else{
			count = 0;
			for(i=x; i<x+l; i++){
				for(j=y; j<y+l; j++){
					count += board[i][j];
				}
			}
			printf("%d\n", count);
		}
	}
	return 0;
}
