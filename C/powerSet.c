//printt power set 
#include <stdio.h>
#include<math.h>
int main(void) 
{
	char set[10]; 
	int n, i, j;
	scanf("%d", &n);
	for(i=0; i<n; i++)
	{
		scanf(" %c", &set[i]);
	}
	int m= pow(2,n);
	int b=0;
	int k=0;
	for(j=0; j<m; j++)
	{
		i=0;
		k=j;
		while(k>0)
		{
			b=k%2;
			if(b==1)
			{
				printf("%c", set[i]);
				i++;
			}
			else i++;
			k=k/2;
		}
		printf("\n");
	}
	return 0;
    }
