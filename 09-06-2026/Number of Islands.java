class Solution {
    private final int[][] diff = {
        {-1, 0},
        {1, 0},
        {0, -1},
        {0, 1}
    };

    public int numIslands(char[][] grid) {
        if (grid == null || grid.length == 0) {
            return 0;
        }

        int R = grid.length;
        int C = grid[0].length;
        int islands = 0;
        for (int row = 0; row < R; row++) {
            for (int col = 0; col < C; col++) {

                if (grid[row][col] == '1') {
                    islands++;
                    dfs(grid, R, C, row, col);
                }
            }
        }
        return islands;
    }

    private void dfs(char[][] grid, int R, int C, int row, int col) {

        grid[row][col] = '0';
        for (int i = 0; i < 4; i++) {
            int adjRow = row + diff[i][0];
            int adjCol = col + diff[i][1];

            if (adjRow >= 0 && adjRow < R && adjCol >= 0 && adjCol < C && grid[adjRow][adjCol] == '1') {
                dfs(grid, R, C, adjRow, adjCol);
            }
        }
    }
}
