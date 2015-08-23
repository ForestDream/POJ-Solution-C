#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 201
char in[MAX], out[MAX];
int N, flag[MAX]; //flag 为1 表示in[]字符串(按增序排列以后)里对应的字符 已经 添加到out[]中

int cmp(const void * a,const void * b)
{
    return *(char * )a - *(char *)b;
}

void pl(int n){
	if(n == N){
		//printf("%s\n", out); //输出字符串
		puts(out);
		return;
	}
	for(int i=0; i<N; i++){
		if(!flag[i]){
			out[n] = in[i]; //将in中字符添加到out
			flag[i] = 1;
			pl(n+1);
			flag[i] = 0;
			/* 添加out[]的每一个字符时跳过重复字母 */
			while(i<N-1 && in[i]==in[i+1])
				i++;
		}
	}
}
int main(){
	
	scanf("%s", in);
	N = strlen(in);
	out[N] = '\0';
	qsort(in, N, sizeof(char), cmp);
	pl(0);
	return 0;
}
