class Solution {
public:

/*5.1.3 Problem 3 - Search in Matrix II
You are given a 2D array, m, with n rows and n columns. We know that
mi,0 ≤ mi,1 ≤ . . . ≤ mi,n−1
and
m0,i ≤ m1,i ≤ . . . ≤ mn−1,i
for all 0 ≤ i < n. Find the position of value x (if it exists). Try finding an
O(n log n) time algorithm. Can you find an O(n) time complexity algorithm?
If not obvious, prove the time complexity.
*/

#include <vector>

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();

        int i = m - 1; 
        int j = 0;

        while (i >= 0 && j < n) {
            if (matrix[i][j] == target)
                return true;
            else if (matrix[i][j] < target)
                j++;
            else
                i--;
        }

        return false;
    }
};