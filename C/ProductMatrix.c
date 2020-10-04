//Product of two matrixes
#include<stdio.h>
int main()
{
    int i,j,k,n,m,n1,m1,c;
    scanf("%d",&n);   //no of rows in array/matrix 1
    scanf("%d",&m);   //no of columns in array/matrix 1
     scanf("%d",&n1);  //no of rows in array/matrix 2
    scanf("%d",&m1);   //no of columns in array/matrix 2
    int arr[n][m],arr1[n1][m1];
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            scanf("%d",&arr[i][j]);
        }
    }
        for(i=0;i<n1;i++)
    {
        for(j=0;j<m1;j++)
        {
            scanf("%d",&arr1[i][j]);
        }
    }
if(m==n1)
{
    int arr2[n][m1];
    for(i=0;i<n;i++)
    {
        for(j=0;j<m1;j++)
        {
         for(k=0,c=0;k<n1;k++)
         {
             c+=arr[i][k]*arr1[k][j];
         }
         arr2[i][j]=c;
        }
}
for(i=0;i<n;i++)
{
    for(j=0;j<m1;j++)
    {
        
    printf("%d ",arr2[i][j]);
    }
    printf("\n");
}
}
}
