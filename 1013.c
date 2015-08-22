/*
* 硬币的状态码：
* 0表示未知，1表示真，2表示假的而且比真的重，3表示假的而且比真的轻
* 事件：even, up_left, up_right, up_0, down_left, down_right, down_0
* code之前画好状态转换图可以防止漏掉某个case
*/

#include<stdio.h>
#include<string.h>

void main(){
    int n;
    
    scanf("%d", &n);
    while(n-- > 0){
        int coin[12] = {0};
        char left[7];
        char right[7];
        char r[5];
        int num;
        int i;
        int j;
        int k;
        
        for(i=0; i<3; i++){
            scanf("%s", left);
            num = strlen(left);
            scanf("%s", right);
            scanf("%s", r);
            //printf("[i=%d]%s %s %s\n", i, left, right, r);
            
            /* even case */
            if(r[0] == 'e'){
                for(j=0; j<num; j++){
                    coin[left[j]-'A'] = 1;
                    coin[right[j]-'A'] = 1;
                }
            }
            /* up case */
            else if(r[0] == 'u'){
                for(k=0; k<12; k++){
                    /* left, right 里的硬币 */
                    for(j=0; j<num; j++){
                        if(k == left[j]-'A'){
                            if(coin[k] == 0)
                                coin[k] = 2;
                            else if(coin[k] == 3)
                                coin[k] = 1;
                            break;
                        }
                        if(k == right[j]-'A'){
                            if(coin[k] == 0)
                                coin[k] = 3;
                            else if(coin[k] == 2)
                                coin[k] = 1;
                            break;
                        }                       
                    }
                    /* left，right 之外的硬币一定为真 */
                    if(j == num){     
                        coin[k] = 1;
                    }
                }
            }
            /* "down" case */
            else{
                for(k=0; k<12; k++){
                    /* left，right 里的硬币 */
                    for(j=0; j<num; j++){
                        if(k == left[j]-'A'){
                            if(coin[k] == 0)
                                coin[k] = 3;
                            else if(coin[k] == 2)
                                coin[k] = 1;
                            break;
                        }
                        if(k == right[j]-'A'){
                            if(coin[k] == 0)
                                coin[k] = 2;
                            else if(coin[k] == 3)
                                coin[k] = 1;
                            break;
                        }
                    }
                    /* left，right 之外的硬币一定为真 */
                    if(j == num){
                        coin[k] = 1;
                    }
                }
            }
            /* for(k=0; k<12 ;k++){
                printf("%d  ", coin[k]);
            }
            printf("\n"); */
        }
        
        for(k=0; k<12 ;k++){
            if(coin[k] == 2){
                printf("%c is the counterfeit coin and it is heavy.\n", 'A'+k);
            }
            else if(coin[k] == 3){
                printf("%c is the counterfeit coin and it is light.\n", 'A'+k);
            }
        }
    }
}
