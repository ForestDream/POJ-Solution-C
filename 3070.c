#include<stdio.h>
#define MAX 30

typedef struct Matrix{
	int a[2][2];
}Matrix;

Matrix A = {{{1, 1}, {1, 0}}};
Matrix E = {{{1, 0}, {0, 1}}};
/* 矩阵乘法 */
Matrix mul(Matrix a, Matrix b){
	Matrix ans;
	for(int i=0;i<2;i++){
		for(int j=0;j<2;j++){
			ans.a[i][j]=0;
			for(int k=0;k<2;k++)
				ans.a[i][j]+=a.a[i][k]*b.a[k][j];
			ans.a[i][j] %= 10000;
		}
    }
  return ans;
}

int main(){
	int n, i;
	Matrix ans, pow_A[MAX];
	pow_A[0] = A;
	for(i=1; i<MAX; i++){
		pow_A[i] = mul(pow_A[i-1], pow_A[i-1]);
	}
	
	while(scanf("%d", &n) != EOF && n != -1){
		i = 0, ans = E;
		/* 矩阵快速幂 */
		while(n){
			if(n&1)
				ans =  mul(ans, pow_A[i]);
			n >>= 1;
			i++;
		}
		printf("%d\n", ans.a[0][1]);
	}
	return 0;
}
