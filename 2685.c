/*
* Numberal System
* Rules:
* only use m, x, c, i, 2, 3, 4, 5, 6, 7, 8, 9
* m=1000, x=100, c=10, i=10
* m,x,c,i  left-to-right
* m,x,c,i only one occurrence
* m,x,c,i with a prefix or no prefix
* m,x,c,i may omit, but not empty
* eg.  "5m2c3x4i", "m2c4i", "5m2c3x"
*/

#include<stdio.h>
#include<string.h>
#include<string.h>

int MCXI_2_DEC(const char* num_MCXI){
	int num = 0;
	for(int i=0; i<8; i++){
		if(num_MCXI[i]>='2' && num_MCXI[i]<='9'){ 
			switch(num_MCXI[i+1]){
				case 'm':
					num += (num_MCXI[i]-48) * 1000;
					break;
				case 'c':
					num += (num_MCXI[i]-48) * 100;
					break;
				case 'x':
					num += (num_MCXI[i]-48) * 10;
					break;
				case 'i':
					num += num_MCXI[i] - 48;
					break;
				default:
					break;
			}
			if(num_MCXI[i+1] == 'i')
				break;
			i++;
		}else{
			switch(num_MCXI[i]){
				case 'm':
					num += 1000;
					break;
				case 'c':
					num += 100;
					break;
				case 'x':
					num += 10;
					break;
				case 'i':
					num += 1;
					break;
				default:
					break;
			}
			if(num_MCXI[i] == 'i')
				break;
		}
	}
	return num;
}

void main(){
	int n;
	char MCXI[5] = "mcxi";

    scanf("%d", &n);
    while(n--){
		int a;
		int b;
		int sum;
		int coeff;
		int j;
		char a_MCXI[9] = "";
		char b_MCXI[9] = "";
		char sum_MCXI[9] = "";
		int tmp = 1000;
		
        /* 输入MXCI-string */
        scanf("%s %s", a_MCXI, b_MCXI);
        
        /* 转换为十进制，并相加 */
        a = MCXI_2_DEC(a_MCXI);
		b = MCXI_2_DEC(b_MCXI);
		sum = a + b;
        //printf("%d %d %d\n", a, b, sum);
		
        /* 和转换为MXCI-string */
		j = 0; /* index of sum_MCXI[9] */
        for(int i=0; i<4; i++){
			
			coeff = sum/tmp;
			if(coeff >= 2 && coeff <= 9){
				sum_MCXI[j++] = (char)(coeff + 48);
				sum_MCXI[j++] = MCXI[i];
				sum -= coeff * tmp;
			}else if(coeff == 1){
				sum_MCXI[j++] = MCXI[i];
				sum -= coeff * tmp;
			}
			tmp /= 10;
			//printf("%d --- %d --- %s\n", coeff, sum, sum_MCXI);
		}
		
        /* 输出和的MXCI-string表示 */
        printf("%s\n", sum_MCXI);
    }
}
