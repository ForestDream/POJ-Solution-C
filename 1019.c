/* 
* 打表：程序中打表
* lower_bound 从已排序数组里，找小于指定值的最大元素，原理是二分法
* 算法过程：用 lower_bound 确定 n 所在的 group，然后在用 lower_bound 确定 n 所在的整数，将整数打印成字符串，最后打印出指定位数上的数字
*/

#include<stdio.h>
#define MAX 35000

unsigned int group[MAX+1] = {0}; /* group[k]表示S1……Sk中所有数字的个数 */
unsigned int groupSum[MAX+1] = {0}; /* groupSum[k]表示group[1]……group[k]的和 */

unsigned int getGroupLength(int n){
    int len;
    if(n<10)
        len = n;
    else if(n<100)
        len = 9 + (n-9)*2;
    else if(n<1000)
        len = 9 + 90*2 + (n-99)*3;
    else if(n<10000)
        len = 9 + 90*2 + 900*3 + (n-999)*4;
    else if(n<100000)
        len = 9 + 90*2 + 900*3 + 9000*4 + (n-9999)*5;
    return len;
}

void init(){
    for(int i=1; i<=MAX; i++){
        group[i] = getGroupLength(i);
        groupSum[i] = groupSum[i-1] + group[i];
    }
}

/* 从已排序数组里，找小于指定值的最大元素，原理是二分法 */
unsigned int lower_bound(unsigned int *A,unsigned int len,int val){
	unsigned int left=0;
    unsigned int right=len;
	while(left<right){
        int m=(left+right)/2;
		if(val<=A[m]){
			right=m-1;
        }else{
			left=m+1;
        }	
    }	
    return val<=A[left]?left:left+1;
}

char getDigit(int n){
    char num[12];
    int k;
    //get which group the nth digit is in
    k = lower_bound(groupSum, MAX+1, n);
    //printf("the %uth digit is in the %uth group\n", n, k);
    //get which position the nth digit is in the kth group
    n -= groupSum[k-1];
    //get which number the nth digit is in the kth group
    k = lower_bound(group, MAX+1, n);
    //get the number in string
    sprintf(num, "%d", k);
    //get the digit
    return num[n-group[k-1]-1];
}

void main(){
    int t;
    int n;
    
    init();
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        putchar(getDigit(n));
        putchar('\n');
    }
}
