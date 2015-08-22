/*
* 经典DP
* 用递归下的记忆化搜索实现
*/

#include<stdio.h>

int m[100][100];
int cnt[100][100];
int row;
int col;

int DP(int i, int j){
    int max = 0;
    /* 如果已经处理过，直接返回 */
    if(cnt[i][j] > 0){
        return cnt[i][j];
    }
    /* 以下四块，只对合法的 i 和 j 进行递归 */
    /* 向右 */
    if(j>0 && m[i][j]>m[i][j-1]){
        if(max < DP(i, j-1)){
            max = DP(i, j-1);
        }
    }
    /* 向左 */
    if(j<col-1 && m[i][j]>m[i][j+1]){
        if(max < DP(i, j+1)){
            max = DP(i, j+1);
        }
    }
    /* 向下 */
    if(i>0 && m[i][j]>m[i-1][j]){
        if(max < DP(i-1, j)){
            max = DP(i-1, j);
        }
    }
    /* 向上 */
    if(i<row-1 && m[i][j]>m[i+1][j]){
        if(max < DP(i+1, j)){
            max = DP(i+1, j);
        }
    }
    
    cnt[i][j] = max + 1;
    return cnt[i][j];
}

void main(){
    int i, j;
    
    scanf("%d %d", &row, &col);
    /* 初始化数据 */
    for(i=0; i<row; i++){
        for(j=0; j<col; j++){
            scanf("%d", &m[i][j]);
            cnt[i][j] = 0;
        }
    }
    /* 处理每个点，将其最大滑雪长度保存在cnt数组里面；并将矩阵中的最大值保存在cnt[0][0] */
    for(i=0; i<row; i++){
        for(j=0; j<col; j++){
            DP(i, j);
        }
    }
    for(i=0; i<row; i++){
        for(j=0; j<col; j++){
            if (cnt[0][0] < cnt[i][j]){
                cnt[0][0] = cnt[i][j];
            }
        }
    }
    printf("%d\n", cnt[0][0]);
}
