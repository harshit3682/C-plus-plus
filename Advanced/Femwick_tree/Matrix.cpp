#include <vector>
#include <iostream>

class NumMatrix {
private:
    std::vector<std::vector<int>> bit; // 2D Fenwick Tree
    std::vector<std::vector<int>> matrix; // Original matrix
    int numRows;
    int numCols;

public:
    NumMatrix(std::vector<std::vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) {
            numRows = 0;
            numCols = 0;
            return;
        }

        this->numRows = matrix.size();
        this->numCols = matrix[0].size();
        this->matrix = matrix; // Store a copy of the original matrix
        
        // Initialize BIT with dimensions (numRows + 1) x (numCols + 1) for 1-based indexing
        bit.assign(numRows + 1, std::vector<int>(numCols + 1, 0));

        // Build the Fenwick Tree by performing updates for all initial elements
        for (int i = 0; i < numRows; ++i) {
            for (int j = 0; j < numCols; ++j) {
                // Initial update adds matrix[i][j] to the BIT
                // We calculate delta from 0 since it's the initial build
                updateBIT(i, j, matrix[i][j]); 
            }
        }
    }

    // Private helper function to update the BIT
    // row, col are 0-indexed input coordinates
    // val is the value to ADD at matrix[row][col]
    void updateBIT(int row, int col, int val) {
        // Adjust to 1-based indexing for BIT operations
        int r_idx = row + 1;
        int c_idx = col + 1;

        while (r_idx <= numRows) {
            int temp_c_idx = c_idx;
            while (temp_c_idx <= numCols) {
                bit[r_idx][temp_c_idx] += val;
                temp_c_idx += (temp_c_idx & -temp_c_idx); // Move to next column ancestor
            }
            r_idx += (r_idx & -r_idx); // Move to next row ancestor
        }
    }

    // Public update function for modifying a cell value
    // row, col are 0-indexed input coordinates
    // val is the new value for matrix[row][col]
    void update(int row, int col, int val) {
        if (numRows == 0 || numCols == 0) return;

        // Calculate the difference between the new value and the old value
        int delta = val - matrix[row][col];
        matrix[row][col] = val; // Update the original matrix

        updateBIT(row, col, delta); // Apply the delta to the BIT
    }

    // Private helper function to get prefix sum from (0,0) to (row,col)
    // row, col are 0-indexed input coordinates
    int queryBIT(int row, int col) {
        int sum = 0;
        // Adjust to 1-based indexing for BIT operations
        int r_idx = row + 1;
        int c_idx = col + 1;

        while (r_idx > 0) {
            int temp_c_idx = c_idx;
            while (temp_c_idx > 0) {
                sum += bit[r_idx][temp_c_idx];
                temp_c_idx -= (temp_c_idx & -temp_c_idx); // Move to previous column predecessor
            }
            r_idx -= (r_idx & -r_idx); // Move to previous row predecessor
        }
        return sum;
    }

//     4. Range Sum Query (rangeQuery(row1, col1, row2, col2))

// You use the inclusion-exclusion principle on the prefix sums:
// Sum(r1,c1,r2,c2) = query(r2,c2) - query(r1-1,c2) - query(r2,c1-1) + query(r1-1,c1-1)
// query(r2, c2): Sum from (0,0) to (r2,c2)
// query(r1-1, c2): Sum from (0,0) to (r1-1,c2) (subtracts the rows above r1)
// query(r2, c1-1): Sum from (0,0) to (r2,c1-1) (subtracts the columns left of c1)
// query(r1-1, c1-1): Sum from (0,0) to (r1-1,c1-1) (added back because it was subtracted twice)
    int sumRegion(int row1, int col1, int row2, int col2) {
        if (numRows == 0 || numCols == 0) return 0;

        return queryBIT(row2, col2) - 
               queryBIT(row1 - 1, col2) - 
               queryBIT(row2, col1 - 1) + 
               queryBIT(row1 - 1, col1 - 1);
    }
};


// Example Usage:
int main() {
    std::vector<std::vector<int>> matrix = {
        {3, 0, 1, 4, 2},
        {5, 6, 3, 2, 1},
        {1, 2, 0, 1, 5},
        {4, 1, 0, 1, 7},
        {1, 0, 3, 0, 5}
    };

    NumMatrix numMatrix(matrix);

    // Initial sumRegion queries
    std::cout << "Sum region (2,1) to (4,3): " << numMatrix.sumRegion(2, 1, 4, 3) << std::endl; // Expected: 8
    std::cout << "Sum region (1,1) to (2,2): " << numMatrix.sumRegion(1, 1, 2, 2) << std::endl; // Expected: 11 (6+3+2+0)
    
    // Update a value
    numMatrix.update(3, 2, 2); // Change matrix[3][2] from 0 to 2
    std::cout << "Updated matrix[3][2] to 2." << std::endl;

    // Query again after update
    std::cout << "Sum region (2,1) to (4,3) after update: " << numMatrix.sumRegion(2, 1, 4, 3) << std::endl; // Expected: 10 (old sum 8 + delta 2)
    std::cout << "Sum region (1,1) to (2,2) after update: " << numMatrix.sumRegion(1, 1, 2, 2) << std::endl; // Expected: 11 (no change as (3,2) is outside this region)

    return 0;
}
