//Spirally traversing a matrix
void printSpiral(int a[ROWS][COLS], int r, int c)
{
  int i,j,k=0,l=0;
  while(k<r&&l<c)
  {
  for(i=l;i<c;i++)
  {
    printf("%d\n",a[k][i]);		//for 1st row
  }k++;
  for(i=k;i<r;i++)
  {printf("%d\n",a[i][c-1]);}		//for last col.
   c--;
 if(k<r){
  for(i=c-1;i>=l;i--)
  {printf("%d\n",a[r-1][i]);}		//for last row
    r--;}
  if(l<c){
  for(i=r-1;i>=k;i--)
  {printf("%d\n",a[i][l]);}		//for 1st col
  l++;}
  }
}