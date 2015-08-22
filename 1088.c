/*
* ����DP
* �õݹ��µļ��仯����ʵ��
*/

#include<stdio.h>

int m[100][100];
int cnt[100][100];
int row;
int col;

int DP(int i, int j){
    int max = 0;
    /* ����Ѿ��������ֱ�ӷ��� */
    if(cnt[i][j] > 0){
        return cnt[i][j];
    }
    /* �����Ŀ飬ֻ�ԺϷ��� i �� j ���еݹ� */
    /* ���� */
    if(j>0 && m[i][j]>m[i][j-1]){
        if(max < DP(i, j-1)){
            max = DP(i, j-1);
        }
    }
    /* ���� */
    if(j<col-1 && m[i][j]>m[i][j+1]){
        if(max < DP(i, j+1)){
            max = DP(i, j+1);
        }
    }
    /* ���� */
    if(i>0 && m[i][j]>m[i-1][j]){
        if(max < DP(i-1, j)){
            max = DP(i-1, j);
        }
    }
    /* ���� */
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
    /* ��ʼ������ */
    for(i=0; i<row; i++){
        for(j=0; j<col; j++){
            scanf("%d", &m[i][j]);
            cnt[i][j] = 0;
        }
    }
    /* ����ÿ���㣬�������ѩ���ȱ�����cnt�������棻���������е����ֵ������cnt[0][0] */
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
