import java.util.*;

public class Main {

    static int[][] dir = {
        {0,-1},
        {0,1},
        {-1,0},
        {1,0}
    };

    static int dfs(int[][] matrix, int[][] dp, int row, int col){

        if(dp[row][col] != 0)
            return dp[row][col];

        int max = 0;

        for(int[] d : dir){

            int nr = row + d[0];
            int nc = col + d[1];

            if(nr>=0 && nr<matrix.length &&
               nc>=0 && nc<matrix[0].length &&
               matrix[nr][nc] > matrix[row][col]){

                max = Math.max(max,
                        dfs(matrix, dp, nr, nc));
            }
        }

        dp[row][col] = 1 + max;

        return dp[row][col];
    }

    public static void main(String[] args){

        Scanner sc = new Scanner(System.in);

        int R = sc.nextInt();
        int C = sc.nextInt();

        int[][] matrix = new int[R][C];

        for(int i=0;i<R;i++)
            for(int j=0;j<C;j++)
                matrix[i][j]=sc.nextInt();

        int[][] dp=new int[R][C];

        int ans=1;

        for(int i=0;i<R;i++)
            for(int j=0;j<C;j++)
                ans=Math.max(ans,dfs(matrix,dp,i,j));

        System.out.println(ans);
    }
}
