import java.util.Scanner;
import java.lang.Math; 
// Other imports go here// Do NOT change the class name
class Main
{
    public static void main(String[] args)
    {
       Scanner sc=new Scanner(System.in);
      int n=sc.nextInt();
      int i,a=0,j,c=0,num,nn,x,y=0,aa=0,yy=0;
      while(n-->0)
      {
        c=0;
        
         num=sc.nextInt();
         int ss=num;
        num=(int)(Math.pow(num,2));
        nn=num;
        while(num>0)
        {
          a=(num%10);
          num=(num/10);
          c++;
        }
        x=c/2;
       if(c%2==0 || c==1)
       {
         a=(int)(nn%Math.pow(10,x));
         y=(int)(nn/Math.pow(10,x));
       }
       else 
       {
           a=(int)(nn%Math.pow(10,x));
         y=(int)(nn/Math.pow(10,x)); 
         aa=(int)(nn%Math.pow(10,x+1));
         yy=(int)(nn/Math.pow(10,x+1)); 
         
       }
        if(ss==a+y || (ss==a+y || ss==aa+yy) )
        System.out.println("1");
        else
        System.out.println("0");
      }
    }
}