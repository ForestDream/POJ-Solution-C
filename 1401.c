#include<stdio.h>
#include<math.h>

int main(){
	int t, n, i, z;
	int pow_5[13];
	scanf("%d", &t);
	
	pow_5[0] = 5;
	for(i=1; i<13; i++){
		pow_5[i] = 5*pow_5[i-1];
	}
	
	while(t--){
		scanf("%d", &n);
		i = 0;
		z = 0;
		while(pow_5[i] <= n){
			z += n / pow_5[i];
			i++;
		}
		printf("%d\n", z);
	}
	return 0;
}
