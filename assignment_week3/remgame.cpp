#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

bool canWin(vector<vector<int>>& board, unordered_map<string, bool>& memo) {
    // Convert board to a string representation for memoization
    string board_str = "";
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            board_str += to_string(board[i][j]);
        }
    }
    
    // Check memoization table
    if (memo.find(board_str) != memo.end()) {
        return memo[board_str];
    }
    
    // Check if there's any move that leads to a losing position for the opponent
    for (int i = 0; i < 5; ++i) {
        for (int j = 1; j <= 5; ++j) {
            // Try removing j pieces from row i
            bool valid_move = false;
            for (int k = 0; k <= 5 - j; ++k) {
                bool can_remove = true;
                for (int p = k; p < k + j; ++p) {
                    if (board[i][p] == 0) {
                        can_remove = false;
                        break;
                    }
                }
                if (can_remove) {
                    vector<vector<int>> new_board = board;
                    for (int p = k; p < k + j; ++p) {
                        new_board[i][p] = 0;
                    }
                    if (!canWin(new_board, memo)) {
                        valid_move = true;
                        break;
                    }
                }
            }
            if (valid_move) {
                memo[board_str] = true;
                return true;
            }
            
            // Try removing j pieces from column i
            valid_move = false;
            for (int k = 0; k <= 5 - j; ++k) {
                bool can_remove = true;
                for (int p = k; p < k + j; ++p) {
                    if (board[p][i] == 0) {
                        can_remove = false;
                        break;
                    }
                }
                if (can_remove) {
                    vector<vector<int>> new_board = board;
                    for (int p = k; p < k + j; ++p) {
                        new_board[p][i] = 0;
                    }
                    if (!canWin(new_board, memo)) {
                        valid_move = true;
                        break;
                    }
                }
            }
            if (valid_move) {
                memo[board_str] = true;
                return true;
            }
        }
    }
    
    // If no winning move found, mark this board configuration as losing
    memo[board_str] = false;
    return false;
}

int main() {
    int n;
    cin >> n;
    
    while (n--) {
        vector<vector<int>> board(5, vector<int>(5));
        
        // Read the board configuration
        for (int i = 0; i < 5; ++i) {
            for (int j = 0; j < 5; ++j) {
                cin >> board[i][j];
            }
        }
        
        // Memoization map
        unordered_map<string, bool> memo;
        
        // Check if the first player can force a win from this board configuration
        if (canWin(board, memo)) {
            cout << "winning" << endl;
        } else {
            cout << "losing" << endl;
        }
    }
    
    return 0;
}
