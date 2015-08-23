#include<stdio.h>
typedef struct node{
	int value;
	struct node *pre;
	struct node *next;
}Node;
/* 顺序遍历链表 */
void travel1(Node *start, int n){
	Node *cur;
	cur = start;
	printf("%d", cur->value);
	while(n-- -1){
		cur = cur->next;
		printf(" %d", cur->value);
	}
	printf("\n");
}
/* 倒序遍历链表 */
void travel2(Node *end, int n){
	Node *cur;
	cur = end;
	printf("%d", cur->value);
	while(n-- -1){
		cur = cur->pre;
		printf(" %d", cur->value);
	}
	printf("\n");
}

int main(){
	int t, n, i, j;
	Node spade[13] = {0, NULL, NULL};
	Node *start, *end, *tmp;
	
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);

		spade[0].value = n;
		start = &spade[0];
		end = &spade[0];
		
		for(i=1; i<n; i++){
			/* 插入新结点 */
			spade[i].value = n-i;
			spade[i].next = start;
			start->pre = &spade[i];
			spade[i].pre = end;
			end->next = &spade[i];
			
			/* 头指针和尾指针移动位置 */
			/* end = &spade[i];
			for(j=i; j<n; j++){
				end = end->next;
			}
			start = end->next; */
			
			start = &spade[i];
			for(j=i; j<n; j++){
				start = start->pre;
			}
			end = start->pre;
		}
		// travel2(end, n);
		travel1(start, n);
	}
	return 0;
}
