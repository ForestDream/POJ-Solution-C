#include<stdio.h>

int main(){
	int t, i;
	int num_arr[5];
	
	scanf("%d", &t);
	while(t--){
		for(i=0; i<4; i++){
			scanf("%d", num_arr+i);
			
		}
		if(num_arr[3]-num_arr[2] == num_arr[2]-num_arr[1])
			num_arr[4] = num_arr[3] + num_arr[3] - num_arr[2];
		else
			num_arr[4] = num_arr[3] * num_arr[3] / num_arr[2];
		for(i=0; i<5; i++){
			printf("%d ", num_arr[i]);
		}
		printf("\n");
	}
	return 0;
}
