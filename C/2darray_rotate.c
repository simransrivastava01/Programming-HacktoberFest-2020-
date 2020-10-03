#include <stdio.h>
int main()
{
	int t;
  scanf("%d",&t);
  while(t--)
  {
    int r,c;
    scanf("%d",&r);
    c=r;
    int a[r][c];
    int i,j;
    for(i=0;i<r;i++)
      for(j=0;j<c;j++)
        scanf("%d",&a[i][j]);
		for(i=0;i<r;i++)
        {
          for(j=i;j<c;j++)
          {
            int temp=a[i][j];
            a[i][j]=a[j][i];
            a[j][i]=temp;
          }
        }
    for(i=0;i<r;i++)
    {
      for(j=0;j<c/2;j++)
      {
        int temp=a[i][r-1-j];
        a[i][r-1-j]=a[i][j];
        a[i][j]=temp;
      }
    }
        for(i=0;i<r;i++)
        {   for(j=0;j<c;j++)
      {
          if(j==c-1)
            printf("%d",a[i][j]);
          else
        printf("%d ",a[i][j]);
      }	
         printf("\n");
        }
 
    printf("\n");
  }
    return 0;
}