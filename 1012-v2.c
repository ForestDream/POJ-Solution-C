/*
* 因为每次都要将后半部分的人踢出去，所以每次踢完以后可以重新排号，只要下次踢的人还是后半部分的即可
* 不需要模拟，不用结构体，不用指针的移动，简单快捷
* 提交时保存不同k的计算结果，防止重复计算引起超时
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
            /* 取不同的m，开始踢人 */
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
