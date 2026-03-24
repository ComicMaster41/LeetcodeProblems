class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        /*
        since we want to return the product matrix, we need to iterate over the entire matrix, maybe we can just return the orignal matrix modified?

        how do we effectively grab all the elements that arent the one we're at and add them together?

        i also wonder if we can just take all the elements into a singular array and multiply them all together then replace the ith element in the matrix. to elaborate, we put all the elements in an array. then we have an index counter that starts at the beginning 

        so the way to go about it is to get the produt of all the rows and columns
        */


        // flatten matrix
        vector<int> flatGrid;
        for (const auto & v : grid)
            flatGrid.insert(flatGrid.end(), v.begin(), v.end()); 
        int n = flatGrid.size();

        vector<int> prefix(n, 1);
        vector<int> suffix(n, 1);

        for (int i = 1; i < n; i++) {
            prefix[i] = (1LL * prefix[i - 1] * flatGrid[i - 1]) % 12345;
        }

        for (int i = n - 2; i >= 0; i--) {
            suffix[i] = (1LL * suffix[i + 1] * flatGrid[i + 1]) % 12345;
        }

        // next make the grid product
        int rows = grid.size();
        int cols = grid[0].size();
        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                int i = row * cols + col;
                grid[row][col] = (prefix[i] * suffix[i]) % 12345;
            }
        }

        return grid;
    }
};
