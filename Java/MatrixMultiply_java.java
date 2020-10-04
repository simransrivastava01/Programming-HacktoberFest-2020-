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
     y=in.nextInt();
 int a[][]=new int[x][y];
 for(i=0;i<x;i++)
 {
     for(j=0;j<y;j++)
     {
         a[i][j]=in.nextInt();
     }
 }
    int v,w;
    v=in.nextInt();
     w=in.nextInt();
    int b[][]=new int[v][w];
 for(i=0;i<v;i++)
 {
     for(j=0;j<w;j++)
     {
        b[i][j]=in.nextInt();
     }
 }
    int k;
    int s[][]=new int[x][w];
    for(i=0;i<x;i++)
 {
     for(j=0;j<w;j++)
     {
       s[i][j]=0;
       for(k=0;k<y;k++)
       {
         s[i][j]=s[i][j]+((a[i][k]*b[k][j]));
       }
     }
    }
    for(i=0;i<x;i++)
 {
     for(j=0;j<w;j++)
     {
      System.out.print(s[i][j]+" ");
     }
       System.out.print("\n");
    }
  }
}
       
       
    
    
  }