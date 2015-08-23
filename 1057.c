#include<stdio.h>
#include<stdlib.h>
#include<string.h>

static int n;

typedef struct node{
	char *name;
	int depth;
	int num;
	struct node **child;
}LNODE;

int cmp(char *a, char *b){
	if(a[0] == 'd' && b[0] == 'd')
		return 1;
	else
		return strcmp(a, b);
}

void map(LNODE *root_node, LNODE **list, char *a){
	int i;
	while(a[0] != '#' && a[0] != '*'){
		if(a[0] == ']'){
			gets(a);
			break;
		}
		if(n == 0){
			list = (LNODE **)malloc((++n)*sizeof(LNODE *));
		}
		else{
			list = (LNODE **)realloc(list,(++n)*sizeof(LNODE *));
		}
		list[n-1] = (LNODE *)malloc(sizeof(LNODE));
		list[n-1]->child  = NULL;
		list[n-1]->num = 0;
		list[n-1]->depth = root_node->depth + 1;
		list[n-1]->name = (char *)malloc(10*sizeof(char));
		strcpy(list[n-1]->name, a);
		
		root_node->num++;
		if(root_node->num == 1){
			root_node->child = (LNODE **)malloc(sizeof(LNODE *));
			root_node->child[root_node->num-1] = list[n-1];
		}
		else{
			root_node->child = (LNODE **)realloc(root_node->child, root_node->num*sizeof(LNODE *));
			/* 插入排序 */
			for(i=root_node->num-2; i>=0 && cmp(list[n-1]->name, root_node->child[i]->name) < 0; i--){
				root_node->child[i+1] = root_node->child[i];
			}
			root_node->child[i+1] = list[n-1];
		}
		
		gets(a);

		if(a[0] != ']'){
			if(list[n-1]->name[0] == 'd'){
				map(list[n-1], list, a);
			}
		}
	}
}

//将map得到的链表输出
void printMap(LNODE *root_node){
	int i, j;
	puts(root_node->name);

	/* root_node有num个子结点，进行遍历 */
	for(i=0; i<root_node->num; i++){
		/* 根据dir和file进行不同缩进 */
		/* 如果子结点是dir */
		if((root_node->child[i])->name[0] == 'd'){
			for(j=0; j<=root_node->depth; j++){
				printf("|     ");
			}
		}
		/* 如果子节是file */
		else if((root_node->child[i])->name[0] == 'f'){
			for(j=0; j<=root_node->depth-1; j++){
				printf("|     ");
			}
		}
		printMap(root_node->child[i]);
	}
}

int main(){
	int count = 0;
	int i;
	char *a = (char *)malloc(10*sizeof(char));
	LNODE head = { "ROOT", 0, 0 ,NULL };
	LNODE *pt = &head;
	LNODE **list;
		
	while(gets(a) && a[0] != '#'){
		n = 0;
		map(pt, list, a);
		printf("DATA SET %d:\n", ++count);
		
		//打印链表
		printMap(pt);
		printf("\n");
		
		for(i=0; i<n; i++){
			//free((void *)list[i]->name);
			free((void *)list[i]);
		}
		free((void *)list);
		head.num = 0;
		head.child = NULL;
	}
	free((void *)a);
	return 0;
}