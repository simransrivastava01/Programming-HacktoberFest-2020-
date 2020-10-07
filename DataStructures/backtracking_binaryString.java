
import java.io.*;
import java.util.*;

class Main {
    
    static void printArray(int[] arr,int n){
        for(int i=0;i<n;i++){
            System.out.print(arr[i]+" ");
        }
        System.out.println();
    }
    static void binaryStrings(int[] arr,int n,int i){
        if(i==n){
            printArray(arr,n);
            return;
        }
        
        arr[i]=0;
        binaryStrings(arr,n,i+1);
        
        arr[i]=1;
        binaryStrings(arr,n,i+1);
    }
    
	public static void main (String[] args) {
		Scanner ss= new Scanner(System.in);
		int n= ss.nextInt();
		int arr[]= new int[n];
		binaryStrings(arr,n,0);
	}
}