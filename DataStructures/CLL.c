#include	<stdio.h>
#include	<malloc.h>

//shravani paraswar

struct CLL
{
	int data;
	struct CLL *next;
};

#define	NODEALLOC	(struct CLL*)malloc(sizeof(struct CLL))

struct CLL * CreateCLL (void);
struct CLL *	GetNewNode (int data);
void	DisplayCLL (struct CLL * Head);
struct CLL * EraseCLL(struct  CLL *Head);
struct	CLL * AddAtBegin(struct CLL *Head,int data);
struct	CLL *DeleteNode(struct CLL *Head, int NodeNo);
struct	CLL *InsertAt(struct CLL *Head, int NodeNo, int data);
struct CLL *DeleteAtBegin (struct CLL *Head);


struct CLL *	GetNewNode (int data)
{
	struct CLL *NewNode;
	
	NewNode = NODEALLOC;
	NewNode->data = data;
	NewNode->next = NULL;
}


struct CLL * CreateCLL (void)
{
	struct CLL *Head, *Last ,*current;
	int cnt, n, data;
	
	printf ("Please enter the number of nodes : ");
	scanf ("%d", &n);
	
	for (cnt =0, Head = NULL; cnt < n; cnt++)
	{
		printf ("Enter the data for the node %d : ", cnt);
		scanf ("%d", &data);
		
		current = GetNewNode (data);
		if(Head == NULL)
		{
			Head = Last = current;	
		}
		else
		{
			Last->next = current;
			Last =current;
		}
	}
	
	Last->next = Head;
	return (Head);
}

void	DisplayCLL (struct CLL * Head)
{
	struct CLL *current = Head;
	
	if (current)
	{
		do
		{
			printf ("%d-->", current->data);
			current = current->next;
		}while (current != Head);
	}
}

struct CLL * EraseCLL(struct  CLL *Head)
{
	struct CLL *Current, *Temp, *Next;
	
	Temp = Head;
	
	if(Temp)
	{
		Current = Head;
		do
		{
			Next = Current->next;
			free (Current);
			Current = Next;
		}while(Current != Temp);
		
		Head = NULL;
	}
	
	return (Head);
}

struct	CLL * AddAtBegin(struct CLL *Head, int data)
{
	struct CLL *NewHead, *Last;
	
	NewHead = GetNewNode (data);
	
	Last = Head;
	while(Last->next != Head)
	{
		Last = Last->next;
	}
	
	NewHead->next = Head;
	Last->next = NewHead;
	Head = NewHead;
	
	return (Head);
}

struct	CLL *InsertAt(struct CLL *Head, int NodeNo, int data)
{
	int cnt;
	struct CLL *Current, *NewNode, *Prev;
	
	if (NodeNo == 0)
		Head = AddAtBegin (Head, data);
	else
	{
		for (cnt =0, Current = Head ; cnt < NodeNo; cnt++)
		{
			Prev = Current;
			Current = Current->next;
		}
		NewNode = GetNewNode(data);
		NewNode->next = Current;
		Prev->next = NewNode;
	}
	
	return (Head);
}

struct CLL *DeleteAtBegin (struct CLL *Head)
{
	struct CLL *Temp= Head, *Current = Head;
	
	if(Head->next == Head)
	{
		free (Head);
		Head = NULL;
		return (Head);
	}
	
	while (Current->next != Head)
	{
		Current = Current->next;
	}
	
	/*Current is at Last*/
	Current->next = Head->next;
	Temp = Head->next;
	free (Head);
	Head = Temp;
	
	return (Head);
}

struct	CLL *DeleteNode(struct CLL *Head, int NodeNo)
{
	int cnt;
	struct CLL *Current, *NewNode, *Prev;
	
	if(NodeNo == 0)
		Head = DeleteAtBegin(Head);
	else
	{
	
		for (cnt =0, Current = Head ; cnt < NodeNo; cnt++)
		{
			Prev = Current;
			Current = Current->next;
		}
		
		Prev->next = Current->next;
		free(Current);
	}
	
	
	return (Head);
}


void	main (void)
{
	struct CLL *Head;
	
	Head = CreateCLL ();
	printf ("\nYou have entered : \n");
	DisplayCLL (Head);
	
	Head= AddAtBegin(Head, 5);
	printf ("\nAfter add at begin : \n");
	DisplayCLL (Head);
	
	Head= InsertAt(Head, 2, 15);
	printf ("\nAfter add at begin : \n");
	DisplayCLL (Head);
	
	Head= DeleteAtBegin(Head);
	printf ("\nAfter delete at begin : \n");
	DisplayCLL (Head);
	
	Head= DeleteNode(Head, 2);
	printf ("\nAfter delete at begin : \n");
	DisplayCLL (Head);
	
	Head = EraseCLL(Head);
	printf ("\nAfter erase : \n");
	DisplayCLL (Head);
}



