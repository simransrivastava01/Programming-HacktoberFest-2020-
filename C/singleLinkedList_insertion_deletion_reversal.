#include <stdio.h>
#include<stdlib.h>
 
struct node{
	int data;
	struct node *next;
};

struct node *create(int n)
{
	if(n==0)
	{
		printf("Empty linked list\n");
		return;
	}
	int i=1, value[n];
	struct node *first, *temp;
	first= (struct node*) malloc(sizeof(struct node));
	//take data of node 
	printf("Enter value to create a node\n");
    scanf("%d", &value[1]);
    first->data= value[1];
    first->next= NULL;
    temp= first;
    
    struct node *newnode;
    for(i=2; i<=n; i++)
    {
    	newnode= (struct node*) malloc(sizeof(struct node));
    	 if(newnode== NULL)
            {
                printf(" Memory can not be allocated\n");
                break;
            }
        else
        {
    		printf("Enter value of node %d\n", i);
    		scanf("%d", &value[i]);
    		newnode->data= value[i];
    		temp->next=newnode;
    		temp= temp->next;
    		newnode->next= NULL;
    		
        }
    }
    return first;
}

struct node *insertWhenEmpty(int data)
{
	struct node *temp;
	temp = (struct node*)malloc(sizeof(struct node));
	temp->data= data;
	temp->next= NULL;
	return temp;
}

struct node* insertAtBeg(struct node* start, int data)
{
	struct node *temp;
	temp= (struct node*)malloc(sizeof(struct node));
	temp->next= start;
	temp->data= data;
	return temp;
}
 
struct node* insertAtEnd(struct node *start, int data)
{
	struct node *p, *temp;
	temp= (struct node*)malloc(sizeof(struct node));
	temp->data= data;
	p=start;
	while(p!=NULL)
	{
		if(p->next==NULL)
		{
			p->next= temp;
			break;
		}
		else p= p->next;
		temp->next= NULL;
	}
	return start;
}
 
struct node* insertBefore(struct node* start, int data, int element)
{
	struct node *p, *temp;
	if (start==NULL)
	printf("List is empty\n");
	if(start->data==element)
	{
	temp= (struct node*)malloc(sizeof(struct node));
	temp->next= start;
	temp->data= data;
	return temp;
	}
	p=start;
	while(p!=NULL)
	{
		if(p->next->data==element)
		{
			temp= (struct node*)malloc(sizeof(struct node));
			temp->next=p->next;
			temp->data=data;
			p->next= temp;
			break;
		}
		else p= p->next;
	}
	return start;
}

struct node *deleteFirst(struct node *start)
{
	struct node *p;
	p= start;
	start= start->next;
	free(p);
	return start;
}

struct node *deleteLast(struct node *start)
{
	struct node *p, *q;
	p=start;
	q=start;
	while(p!= NULL)
	{
		if(p->next==NULL)
		{
			q->next= NULL;
			free(p);
			break;
		}
		else 
		{
			q=p;
			p= p->next;
		}
	}
	return start;
}

void deleteOnlyNode(struct node *start)
{
	free(start);
}

struct node *deleteBefore(struct node *start, int element1)
{
	struct node *p, *q;
	p= start;
	q= start;
	if(start->next->data==element1)
	{
		start= start->next;
		free(p);
		return start;
	}
	while(p!= NULL)
	{
		if(p->next->data==element1)
		{
			q->next= p->next;
			free(p);
			break;
		}
		else 
		{
			q= p;
			p= p->next;
		}
	}
	return start;
}

struct node *reverse( struct node *start)
{
	struct node *p, *p1;
	p= start->next;
	p1= start->next;
	start->next= NULL;
	while(p!=NULL)
	{
		if(p->next==NULL)
		{
			p->next= start;
			start=p;
			break;
		}
		else
		{
			p1= p;
			p=p->next;
			p1->next=start;
			start= p1;
		}
	}

	return start;
}

void print(struct node *start)
{
	struct node *p;
	p=start;
	while(p!=NULL)
	{
		printf("%d\t", p->data);
		p= p->next;
	}
	printf("\n");
}
 
 
int main(void) {
struct node *start;
int n;
printf("No. of node you wish to create\n");
scanf("%d", &n);
start= create(n);
while(1)
{
	int choice;
	printf("Enter choice\n0.Exit\n1.Insert at the beginning\n2.Insert when list is empty\n3.Insert at the end\n4.Insert before a given element\n5.Delete first node\n6.Delete last node\n7.Delete the only node\n8.Delete before a given element\n9.Reverse the list\n");
	scanf("%d", &choice);
	int data;
	if(choice==1 || choice==2 || choice==3 || choice==4)
	{
		//take data for a node
		printf("Enter value\n");
		scanf("%d", &data);
	}
	

	switch(choice)
	{
		case 0: 
		{
			exit(0);
		}
		case 1:
		{
			//int data1;
			//scanf("%d", &data1);
			start= insertAtBeg(start, data); 
			print(start);
			break;
		}
		case 2: 
		{
			//int data2;
			//scanf("%d", &data2);
			start= insertWhenEmpty(data);
			print(start);
			break;
		}
		case 3:
		{
			//	int data3;
			//scanf("%d", &data3);
			start= insertAtEnd(start, data);
			print(start);
			break;
		}
		case 4:
		{
			//int data4;
			//scanf("%d", &data4);
			int element;
			//input value before which you wish to enter node
			printf("Enter value before which you wish to enter node\n");
			scanf("%d", &element);
			start= insertBefore(start, data, element);
			print(start);
			break;
		}
	
		case 5:
		{
			start= deleteFirst(start);
			print(start);
			break;
		}
		case 6:
		{
			start= deleteLast(start);
			print(start);
			break;
		}
		case 7:
		{
			deleteOnlyNode(start);
			printf("List is empty now\n");
			break;
		}
		case 8:
		{
			int element1;
			printf("Enter value before which you wish to delete node\n");
			scanf("%d", &element1);
			start= deleteBefore(start, element1);
			print(start);	
			break;
		}
		case 9:
		{
			start= reverse(start);
			print(start);
			break;
		}
		default: printf("Enter valid choice");
	}
}

return 0;
}
 

