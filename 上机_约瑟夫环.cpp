#include<stdio.h>
#include<stdlib.h>
typedef int ElemType;
//�����㣬����Ϊ��ź����� 
typedef struct Lnode{
	ElemType code;
	int number;
	struct Lnode *next;
}Lnode,*LinkList;

//��ʼ������
void init_Lnode(LinkList &L){
	L = (Lnode*)malloc(sizeof(Lnode));
	L->next = NULL;
} 
//��������(ֻ�ӵڶ���Ԫ�ؿ�ʼ)
void save_Lnode(LinkList &L,int n){
	LinkList p = L;
//	init_Lnode(p);
	L->number = 1;
	scanf("%d",&L->code);
	for(int i = 2;i <= n;i++){
		LinkList s;
		init_Lnode(s);
		scanf("%d",&s->code);
		s->number = i;
		p->next = s;
		p = p->next;
	}
	
	
//	printf("1"); 
} 
//��L������ѭ��
void cir_Lnode(LinkList &L){
	LinkList p = L;
	while(p->next) p = p->next;
	p->next = L;
//	printf("1");
} 
//ɾ��p��ָ���Ԫ�أ���㣩
void delete_Lnode(LinkList &L,LinkList &p){
	LinkList p1 = L;
	while(p1->next != p) p1 = p1->next;
	p1->next = p->next;
//	free(p);
	p = p->next;

} 
//��ѭ��������ָ,�������ɾ����ָԪ�� 
int goal_Lnode(LinkList &L,LinkList &p,int goal){
	for(int i = 1;i < goal;i++){
		p = p->next;
	}
	printf("%d ",p->number);
	goal = p->code;
	delete_Lnode(L,p);
	return goal;
} 


int main(){
	int n = 0;
	int goal = 0;
	scanf("%d%d",&n,&goal);
	LinkList L;	init_Lnode(L);
	LinkList p;// init_Lnode(p);//��ָ��������Ϊ��ͷ 
	p = L;
//	printf("1");
	save_Lnode(L,n);
 
	cir_Lnode(L);//������ѭ���� 
	
	for(int i = 0;i < n;i++){
		goal = goal_Lnode(L,p,goal);
	}
//	goal = 2;
//	goal = goal_Lnode(L,p,goal);
//	printf("%d",goal);
//	for(int i = 0;i < n;i++){
//		printf("%d %d\n",p->code,p->number);
//		p = p->next;
//	}
}

