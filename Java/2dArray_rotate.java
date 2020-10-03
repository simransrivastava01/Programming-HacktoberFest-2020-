import java.util.Scanner;
// Other imports go here, Do NOT change the class name
class Main
{
  public static void main(String[] args)
  {
 int n,l;
    Scanner in=new Scanner(System.in);
  n=in.nextInt();
  for(l=0;l<n;l++)
  {
    int x,y,i,j;
  x=in.nextInt();
 int a[][]=new int[x][x];
 for(i=0;i<x;i++)
 {
     for(j=0;j<x;j++)
     {
         a[i][j]=in.nextInt();
     }
 }
    
   
     for(j=0;j<x;j++)
     {
        for(i=x-1;i>=0;i--)
 {
          if(i>0)
      System.out.print(a[i][j]+" ");
          else
            System.out.print(a[i][j]);
     }
       System.out.print("\n");
    }
    if(l!=n-1)
    System.out.print("\n");
    
  }
}
       
       
    
    
  }