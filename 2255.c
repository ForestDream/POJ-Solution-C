#include<stdio.h>
#include<string.h>

char preOd[27], inOd[27], postOd[27];

void f(int s1, int e1, int s2, int e2, int s3, int e3){
	int len, i;
/* 	printf("执行函数f\n[s1]%d[e1]%d\n", s1, e1);
	for(i=s1; i<=e1; i++){
		printf("%c ", preOd[i]);
	}
	printf("\n"); */
	/* 对根节点的操作 */
	postOd[e3] = preOd[s1];
	if(s1 != e1){
		/* 对左子树的操作 */
		len = 0;
		for(i=s2; i<=e2, inOd[i]!=preOd[s1]; i++)
			len++;
		if(len > 0)
			f(s1+1, s1+len, s2, s2+len-1, s3, s3+len-1);
		/* 对右子数的操作 */
		if(e1>=s1+1+len)
			f(s1+1+len, e1, s2+len+1, e2, s3+len, e3-1);
	}
}
int main(){
	int s1, e1, s2, e2, s3, e3;
	/* 不存储二叉树，直接根据前序和中序确定后序 */
	while(scanf("%s%s", preOd, inOd) != EOF){
		s1 = s2 = s3 = 0;
		e1 = e2 = e3 = strlen(preOd)-1;

		f(s1, e1, s2, e2, s3, e3);
		postOd[e3+1] = '\0';
		// printf("%s\n", postOd);
		puts(postOd);
	}
	return 0;
}
