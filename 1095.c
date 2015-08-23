#include<stdio.h>
#include<stdlib.h>

int *a;

void travel(int m, int na){
	int i,sum=0;
	if(m == 1){
		putchar('X');
		return;
	}
	for(i=0; sum<na; i++){
		sum += a[i]*a[m-1-i];
	}
	i--;
	sum -= a[i]*a[m-1-i];
	na -= sum;
	
	if(i>0){
		putchar('(');
		travel(i,(na-1)/a[m-1-i]+1);
		putchar(')');
	}
	putchar('X');
	
	if(m-1-i>0){
		putchar('(');
		travel(m-1-i,(na-1)%a[m-1-i]+1);
		putchar(')');
	}
}
		
int main(){
	
	int m, i, n;
	
	int *t = (int *)malloc(2 * sizeof(int));
	
	a = (int *)malloc(2 * sizeof(int));
	a[0] = 1, a[1] = 1;
	t[0] = 0, t[1] = 1;
	
	while(scanf("%d",&n) != EOF && n != 0){
		m = 1;
		while(t[m] < n){
			//printf("还未达到n\n");
			m++;
			a = (int *)realloc(a, (m+1)*sizeof(int));
			t = (int *)realloc(t, (m+1)*sizeof(int));
			a[m] = 0;
			for(i=0; i<=m-1; i++){
				a[m] += a[i] * a[m-1-i];
			}
			t[m] = t[m-1] + a[m];
			//printf("[a%d]%d\t[t%d]%d\n",m,a[m],m,t[m]);
		}
		//printf("[%d]%d\n",m,n-t[m-1]);
		travel(m,n-t[m-1]);
		printf("\n");
	}
	free(a);
	free(t);
}