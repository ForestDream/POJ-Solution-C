#include<stdio.h>
#include<stdlib.h>

int main(){
    int max, sum, n;
    int i, j, k;
    int **rect, **rect_m;
    
    scanf("%d", &n);
    /* 为 rect 和 rect_m 分配内存 */
    rect = (int **)malloc(n*sizeof(int *));
    rect_m = (int **)malloc(n*sizeof(int *));
    
    for(i=0; i<n; i++){
        rect[i] = (int *)malloc(n*sizeof(int));
        rect_m[i] = (int *)malloc(n*sizeof(int));
        for(j=0; j<n; j++){
            scanf("%d", &rect[i][j]);
        }
    }
    
    /* 初始化 max 为矩阵左上角的值 */
    max = rect[0][0];
    /* 以第 i 行为起始行，计算最大的矩阵 */
    for(i=0; i<n; i++){
        /* 依次计算从 i 行开始的前 1,2,3......行中的最大矩阵 */
        for(j=i; j<n; j++){
            sum = 0;
            /* 计算 rect_m 矩阵第 j 行（相当于从 rect 矩阵第 i 行到第 j 行的和）中的最大矩阵（其实是一个行向量） */
            for(k=0; k<n; k++){
                if(j == i){
                    rect_m[j][k] = rect[j][k];
                }
                else{
                rect_m[j][k] = rect[j][k] + rect_m[j-1][k];
                }
                sum += rect_m[j][k];
                
                if(sum > max){
                    max = sum;
                }
                if(sum < 0){
                    sum = 0;
                }
                //printf("%d\t",rect_m[j][k]);
            }
            //printf("%d\n", max);
        }
        //printf("\n");
    }
    printf("%d\n", max);
}