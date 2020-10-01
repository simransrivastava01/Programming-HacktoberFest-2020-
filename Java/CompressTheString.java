import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        String input = s.nextLine();
        System.out.println(Solution.compress(input));
    }
}
 class Solution {

	public static String compress(String inputString) {
		// Write your code here
        String ans= new String("");
         int count=0,i;
        for( i=0;i<inputString.length()-1;i++)
        {
if(inputString.charAt(i)==inputString.charAt(i+1))
   {
       if(count==0)
           count+=2;
       else count+=1;
   }
   else
   {
       if(count>0)
       {
           ans+=inputString.charAt(i)+""+count;
              count=0;
       }
       else
       {
           ans+=inputString.charAt(i);
       }
   }
        }
        if(count>0)
            ans+=inputString.charAt(i)+""+count; 
        else
ans+=inputString.charAt(i); 
        return ans;
        

	}

}
