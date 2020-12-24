#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define maxsize 10
typedef int status;
typedef int elemtype;

typedef struct node
{
    elemtype num;
    struct node * next;
}node;

typedef struct node* linklist;

int main(void)
{
    linklist p,q,head;
    int x,n,k,i,j;
    scanf("%d %d",&x,&n);
    if(x==1)
       k=1;
    p=q=(linklist)malloc(sizeof(node)); 
    head=p; 
    head->num=1; 
    for(i=1;i<x;i++)
	{
        p=(linklist)malloc(sizeof(node)); 
        p->num=i+1; 
        q->next=p; 
        q=p;
    }
    q->next=head; 

    p=head; 
    for(i=1;i<x;i++)
	{
        for(j=1;j<n-1;j++)
		{ 
            p=p->next;
        }
            q=p->next; 
            printf("第%d轮淘汰第%d只猴子\n",i,q->num);
            p->next=q->next;
            p=q->next; 
            free(q); 
    }
    k=p->num;
    free(p);
    printf("monkeyKing是第%d\n",k);
}