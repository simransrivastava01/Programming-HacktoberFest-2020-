package array;

import java.util.Scanner;

// a program to do matrix multiplication which takes input from user
// if the columns in 1st matrix are same as rows in 2nd matrix then only it will provide output otherwise it will throw invalid output 

public class MatrixMultiplication {

	public static void main(String[] args) {
		
//input of 1st matrix
		
		Scanner scn = new Scanner(System.in);
		
		int r1 = scn.nextInt();
		int c1 = scn.nextInt();
		
		int one[][] = new int[r1][c1];
		for(int i=0;i<one.length;i++) {
			for(int j=0;j<one[0].length;j++) {
				one[i][j] = scn.nextInt();
			}
		}
		
	//input of 2nd matirx
		
		int r2 = scn.nextInt();
		int c2 = scn.nextInt();
		
		int two[][] = new int[r2][c2];
		for(int i=0;i<two.length;i++) {
			for(int j=0;j<two[0].length;j++) {
				two[i][j] = scn.nextInt();
			}
		}
		
//check for c1 ==r2		
		
		if(c1 != r2)
		{
			System.out.println("invalid input");
			return;
		}
		
//matirx multiplication
		
		int prd[][] = new int[r1][c2];
		for(int i=0;i<prd.length;i++) {
			for(int j=0;j<prd[0].length;j++) {
				
				for(int k=0;k< c1;k++) {
					prd[i][j] += one[i][k] + two[k][j]; 
				}
			}
		}
		
		for(int i=0;i<prd.length;i++) {
			for(int j=0;j<prd[0].length;j++) {
				System.out.println(prd[i][j]);
			}

	   }
	}

}
