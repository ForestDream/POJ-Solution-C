/*
* 使用链表模拟约瑟夫环实现
* 每次删除元素都需要进行m次指针移位的操作
* 时间复杂度高
*/

#include<stdio.h>
#include<stdlib.h>

struct guy{
	int num;
	struct guy* next;
};

void main(){
	int k;
	struct guy* circle;
	
	while(scanf("%d", &k) != EOF && k != 0){
		int m;
		int i;
		
		circle = (struct guy*)malloc(2 * k * sizeof(struct guy));

        /* 取不同的m，开始踢人 */
		for(m=k+1; ; m++){
            
            /* 链表初始化 */
			for(i=0; i<2*k; i++){
				circle[i].num = i+1;
				circle[i].next = &circle[(i+1)%(2*k)];
				//printf("%d %d\n", circle[i].num, circle[i].next);
			}
			
			int left = 2 * k;
			struct guy* kick;
			
			//printf("Value of m: %d\n", m);
			
			/* 测试，输出初始的循环链表 */
			/* printf("Start: ");
			for(int ii=0; ii<left; ii++){
				printf("%d  ", kick->num);
				kick = kick->next;
			}
			printf("\n"); */
			
            /* 从队伍里踢出第一个人 */
            kick = &circle[(m-1)%(2*k)];
            left--;
            //printf("The one out: %2d  Left: %2d\n", kick->num, left);
            *kick = *(kick->next);
            
			while(left > k){
				for(int j=0; j<(m-1)%left; j++){
					kick = kick->next;
				}
				
				if(kick->num > k){
                    left--;
					//printf("The one out: %2d  Left: %2d\n", kick->num, left);
					*kick = *(kick->next);
					
					/* 测试，输出循环链表 */
					/* printf("The rest: ");
					for(int ii=0; ii<left; ii++){
						printf("%d  ", kick->num);
						kick = kick->next;
					}
					printf("\n"); */
				}
				else{
					//printf("Oh,NO! %d is good\n", kick->num);
					break;
				}
			}
            
			if(left == k){
				break;
			}
            if(m%(2*k) == 0){
                m += k;
            }
		}
        free(circle);
		printf("%d\n", m);
	}
}
