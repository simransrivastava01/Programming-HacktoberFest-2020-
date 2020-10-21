
#include <stdio.h>
#include <stdlib.h>
struct Queue
{
 int size;
 int front;
 int rear;
 int *Q;
};
void create(struct Queue *q,int size)
{
 q->size=size;
 q->front=q->rear=-1;
 q->Q=(int *)malloc(q->size*sizeof(int));
}
void enqueue(struct Queue *q,int x)
{
 if(q->rear==q->size-1)
 printf("Queue is Full");
 else
 {
 q->rear++;
 q->Q[q->rear]=x;
 }
}
int dequeue(struct Queue *q)
{
 int x=-1;

 if(q->front==q->rear)
 printf("Queue is Empty\n");
 else
 {
 q->front++;
 x=q->Q[q->front];
 }
 return x;
}
void Display(struct Queue q)
{
 int i;

 for(i=q.front+1;i<=q.rear;i++)
 printf("%d ",q.Q[i]);
 printf("\n");
}
int main()
{ int choice,x,size;
 struct Queue q;
printf("Enter Size:");
scanf("%d",&size);
 create(&q,size);
 while(choice!=3)
{ printf("Enter the choice:\n1.Enqueue\n2.Dequeue\n3.Exit\n");
scanf("%d",&choice);
  if(choice==1)
  {
    printf("Enter value :");
    scanf("%d",&x);
    enqueue(&q,x);
     Display(q);
  }
   if(choice==2)
  {
    
    dequeue(&q);
     Display(q);
  }
}
 return 0;
}