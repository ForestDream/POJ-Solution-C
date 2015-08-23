#include<stdio.h>
#include<math.h>
#define MAX 10
int a, b, pow_9[MAX], pow_10[MAX], pizza[MAX];

int main(){
	int i, j, tmp;
	pow_9[0] = pow_10[0] = 1;
	pizza[0] = 0;
	for(i=1; i<MAX; i++){
		pow_9[i] = pow_9[i-1]*9;
		pow_10[i] = pow_10[i-1]*10;
		for(j=i; j>0; j--){
			pizza[i] += pow_9[i-j]*pow_10[j-1];
		}
		// printf("%d\n", pizza[i]);
	}
	while(scanf("%d", &a) != EOF && a){
		tmp = b = a;
		for(i=0; i<MAX; i++){
			if(tmp){
				if(tmp%10<4)
					b -= (tmp%10) * pizza[i];
				else
					b -= (tmp%10 - 1) * pizza[i] + pow_10[i];
				tmp /= 10;
			}
		}
			
		printf("%d: %d\n", a, b);
	}
	
	return 0;
}
