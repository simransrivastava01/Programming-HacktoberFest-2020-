import java.util.Scanner;
// Other imports go here, Do NOT change the class name
class Main
{
  public static void main(String[] args)
  {

  Scanner obj=new Scanner(System.in);
    
    int t=obj.nextInt();
    
    int i=0,j=0,k=0,l=0,p=0,r1=0,c1=0,r2=0,c2=0;
    
    for(p=0;p<t;p++)
    {
      
    r1=obj.nextInt();  
    c1=obj.nextInt();
    
   int arr[][]=new int[r1][c1];
      
      
      for(i=0;i<r1;i++)
      {
        
        for(j=0;j<c1;j++)
          arr[i][j]=obj.nextInt();
      }
      
   r2=obj.nextInt();  
    c2=obj.nextInt();
    
   int brr[][]=new int[r2][c2];
      
      
      for(i=0;i<r2;i++)
      {
          for(j=0;j<c2;j++)
          brr[i][j]=obj.nextInt();
      }
    
    int crr[][]=new int[r1][c2];
    
    
    for(i=0;i<r1;i++)
    {
      
      for(j=0;j<c2;j++)
      {
        
        for(k=0;k<c1;k++)
        {
          crr[i][j]+=arr[i][k]*brr[k][j];
          
        }
        
      }
      
    }
    
    
    
    
    for(i=0;i<r1;i++)
    {
      for(j=0;j<c2;j++)
      { System.out.print(crr[i][j]+ " ");
      }
      
      System.out.print("\n");
    }
    
    