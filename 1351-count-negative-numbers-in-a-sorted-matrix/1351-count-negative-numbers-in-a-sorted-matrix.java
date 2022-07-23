class Solution {
    public int countNegatives(int[][] grid) {
        int m=grid.length;
        int n=grid[0].length;
        int row=0,col=n-1,p=0;
        while(row<m && col>=0){
            if(col==0 && grid[row][col]<0){
                // if(col==0){
                    p+=n;
                row++;
                // }
                // else{
                // col--;
                // }
            }
            else if(grid[row][col]<0){
                col--;
            }
            else{
                p+=n-col-1;
                row++;
            }
        }return p;
    }
}