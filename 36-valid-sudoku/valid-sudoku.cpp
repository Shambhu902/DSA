class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int rowcase[9][9] = {0};
        int colcase[9][9] = {0};
        int gridcase[9][9] = {0};

        // Traverse every cell
        for(int i = 0; i < board.size(); i++) {

            for(int j = 0; j < board[0].size(); j++) {

                // If it is a number
                if(board[i][j] != '.') {

                    // Convert character to integer
                    int number = board[i][j] - '0';

                    // Find the 3x3 grid number
                    int k = i / 3 * 3 + j / 3;

                    // Check row, column, and grid
                    if(rowcase[i][number - 1]++ ||
                       colcase[j][number - 1]++ ||
                       gridcase[k][number - 1]++) {

                        return false;
                    }
                }
            }
        }

        return true;
    }
};