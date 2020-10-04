
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		

		Scanner s=new Scanner(System.in);
		int n=s.nextInt();
		int k=s.nextInt();
		int a[]=new int[n];
		for(int i=0;i<n;i++)
		{
			a[i]=s.nextInt();
		}
		for(int i=0;i<n;i++)
		{
			if(a[i]==k)
			{
				System.out.println(i);
			}
		}
	}

}