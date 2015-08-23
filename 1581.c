#include<stdio.h>
#include<string.h>

int main(){
	int n, i, j;
	int prbs, pnts, sm[4], pnt[4], mprbs, mpnts;
	char tn[20], wnn[20];
	
	scanf("%d", &n);
	mprbs = mpnts = 0;
	for(j=0; j<n; j++){
		scanf("%s", tn);
		prbs = pnts = 0;
		for(i=0; i<4; i++){
			scanf("%d%d", sm+i, pnt+i);
			if(pnt[i] != 0){
				prbs++;
				pnts += pnt[i] + (sm[i]-1)*20;
			}
		}
		if((prbs > mprbs) || (prbs == mprbs && pnts < mpnts)){
			//printf("这个人比前一个成绩好\n");
			mprbs = prbs;
			mpnts = pnts;
			strcpy(wnn, tn);
		}
		// printf("%s %d %d\n", tn, prbs, pnts);
	}
	printf("%s %d %d\n", wnn, mprbs, mpnts);
		
	return 0;
}
