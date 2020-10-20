import java.util.*;
  class conti_sum{
	public static void main(String[] args){
	int temp1=0;
	int temp=0;
     int[] arr={-2,-3,4,-1,-2,1,5,-3};
	for(int i=0;i<8;i++){
	temp1=temp1+arr[i];
	if(temp<temp1){
	    temp=temp1;
	}
	if(temp1<0){
	   temp1=0;
	  }
	}
System.out.print(temp);
     }
}