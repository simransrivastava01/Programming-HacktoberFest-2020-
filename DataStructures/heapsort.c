/*Heap Sort using max heap*/
#include<stdio.h>
void heapsort(int*arr,int n);
void heapify(int*arr,int n,int i);
int main()
{
	int n,*arr;
	printf("Enter the number of elements:");
	scanf("%d",&n);
	arr=(int*)malloc(sizeof(int)*n);
	printf("Enter %d elements:",n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	heapsort(arr,n);
	printf("The sorted array is:");
	for(int i=0;i<n;i++)
		printf("%d  ",arr[i]);
	return 0;
}

void heapsort(int*arr,int n)
{
	int temp;
	if(n<=1)
		return;
	for(int i=(n-2)/2;i>=0;i--)
	{
		heapify(arr,n,i);
	}
	for(int i=n-1;i>0;i--)
	{
		temp=arr[0];
		arr[0]=arr[i];
		arr[i]=temp;
		
		heapify(arr,i,0);
	}
	
}
//Function to heapify to make max-heap:
void heapify(int*arr,int n,int i)
{
	int temp;
	int largest=i;
	int l=2*i+1;
	int r=2*i+2;
	if(l<n && arr[l]>arr[largest])
		largest=l;
	if(r<n && arr[r]>arr[largest])
		largest=r;
	
	if(largest!=i)
	{
		//swap arr[i] and arr[largest]..
		temp=arr[largest];
		arr[largest]=arr[i];
		arr[i]=temp;
		
		heapify(arr,n,largest);
	}
}

