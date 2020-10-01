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

           spiralPrint(mat);
            System.out.println();

            t -= 1;
        }
    }
    public static void spiralPrint(int matrix[][]){
	int count=0;
        int rows=matrix.length-1;
        int cols=matrix[0].length-1;
        int r=matrix.length;
        int c=matrix[0].length;
        int rs=0,cs=0,ce=cols,re=rows,i;
        while(count<= (r*c)-1)
        {
            
            for(i=cs;i<=ce;i++)
            {
              
                System.out.print(matrix[rs][i]+ " ");
                 count++;
            }
            rs++;
            for(i=rs;i<=re;i++)
            {
                
                 System.out.print(matrix[i][ce] + " ");
                 count++;
            }
            ce--;
             for(i=ce;i>=cs;i--)
            {
                
                  System.out.print(matrix[re][i]+ " ");
                  count++;
            }
            re--;
            for(i=re;i>=rs;i--)
            {
                
                 System.out.print(matrix[i][cs]+ " ");
                 count++;
            }
            cs++;
            
            
            
        }
	}
}


 