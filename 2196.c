#include<stdio.h>

int main(){
	int i, j, tmp;
	int sum1, sum2, sum3;
	for(i=2992; i<10000; i++){
		
		for(j=0, tmp=i, sum1=0; j<4, tmp>0; j++){
			sum1 += tmp % 10;
			tmp /= 10;
		}
		for(j=0, tmp=i, sum2=0; j<4, tmp>0; j++){
			sum2 += tmp % 16;
			tmp /= 16;
		}
		if(sum1 == sum2){
			for(j=0, tmp=i, sum3=0; j<4, tmp>0; j++){
				sum3 += tmp % 12;
				tmp /= 12;
			}
			if(sum1 == sum3)
				printf("%d\n", i);
		}
	}
	return 0;
}
