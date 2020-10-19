import java.util.*;
class rotate_array{
    public static void main(String args[]){
     Scanner scan=new Scanner(System.in);
     int[] arr=new int[5];
	int temp=0;
	for(int i=0;i<5;i++){
	arr[i]=scan.nextInt();
	}
	int c=2;
	for(int i=0;i<c;i++){
	temp=arr[0];
		for(int j=1;j<5;j++){
		arr[j-1]=arr[j];
		}
	   arr[4]=temp;
	}
	for(int i=0;i<5;i++){
	System.out.println(arr[i]);
	}   
    }
}