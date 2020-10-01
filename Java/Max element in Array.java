import java.util.Scanner;
public class Main {

	public static void main(String[] args) {
		
		Scanner s=new Scanner(System.in);
		int n=s.nextInt();
		int a[]= new int[n];
		for(int i=0;i<n;i++)
		{
			a[i]=s.nextInt();
			
		}
		int max=0;
		for(int i=0;i<n;i++)
		{
			if(a[i]>max)
			{
				max=a[i];
			}
		}
		System.out.println("max is  "+ max);

	}

}