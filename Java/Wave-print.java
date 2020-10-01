import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    
    public static int[][] take2DInput() throws IOException {
        String[] strRowsCols = br.readLine().trim().split("\\s");
        int n_rows = Integer.parseInt(strRowsCols[0]);
        int m_cols = Integer.parseInt(strRowsCols[1]);

        if (n_rows == 0) {
            return new int[0][0];
        }


        int[][] mat = new int[n_rows][m_cols];

        for (int row = 0; row < n_rows; row++) {
            String[] strNums; 
            strNums = br.readLine().trim().split("\\s");
            
            for (int col = 0; col < m_cols; col++) {
                mat[row][col] = Integer.parseInt(strNums[col]);
            }
        }

        return mat;
    }


    public static void main(String[] args) throws NumberFormatException, IOException {
        int t = Integer.parseInt(br.readLine().trim());

        while(t > 0) {

            int[][] mat = take2DInput();

            Solution.wavePrint(mat);
            System.out.println();

            t -= 1;
        }
    }
}


 class Solution {

	
	// input - input 2D array
	public static void wavePrint(int input[][]){
		for(int i=0;i<input[0].length;i++)
        {
            if(i%2==0)
        {     for(int j=0;j<input.length;j++)
            {
                System.out.print(input[j][i]+ " ");
            }
        
        }
        else
        { for(int j=input.length-1;j>=0;j--)
            {
                System.out.print(input[j][i]+ " ");
            }
            
        }}
    
        
        
        
        
	}

	
}
