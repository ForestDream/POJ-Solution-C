/*
* ��Ϊÿ�ζ�Ҫ����벿�ֵ����߳�ȥ������ÿ�������Ժ���������źţ�ֻҪ�´��ߵ��˻��Ǻ�벿�ֵļ���
* ����Ҫģ�⣬���ýṹ�壬����ָ����ƶ����򵥿��
* �ύʱ���治ͬk�ļ���������ֹ�ظ���������ʱ
*/

#include<stdio.h>
#include<stdlib.h>

void main(){
    int k;
	int a[14] = {0};
    
    while(scanf("%d", &k) != EOF && k != 0){
        int m;

        if(a[k] != 0){
            printf("%d\n", a[k]);
        }
        else{
            /* ȡ��ͬ��m����ʼ���� */
            for(m=k+1; ; m++){
                int i;
                int kick = (m-1)%(2*k);
                
                for(i=0; i<k && kick>=k; i++){
                    //printf("[m]%2d [min]%2d [kick]%2d bad\n", m, min, kick-k+1);
                    kick = (kick+m-1)%(2*k-i-1);
                }
                if(i == k){
                    //printf("The righht m: %d\n", m);
                    printf("%d\n", m);
                    a[k] = m;
                    break;
                }
                if(m%(2*k) == 0){
                    m += k;
                }
            }
        }
    }
}
