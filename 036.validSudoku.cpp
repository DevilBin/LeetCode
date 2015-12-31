/*************************************************************************
	> File Name: 036.validSudoku.cpp
	> Author: DevilBin 
	> Mail: whu.evil.binary@gmail.com 
	> Created Time: Thu 31 Dec 2015 01:59:51 PM CST
 ************************************************************************/

#include <iostream> 
#include <fstream> 
#include <cstdlib> 
#include <string> 
#include <vector> 
#include <deque> 
#include <list> 
#include <map> 
#include <algorithm> 
#include <sstream> 
#include <climits> 

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char> > & board) {
        if(board.size() == 0) {
            return 0;
        }
        else {
            bool row[9][9] = {{false}};
            bool col[9][9] = {{false}};
            bool block[9][9] = {{false}};
            
            for(unsigned i = 0; i < 9; ++i) {
                for(unsigned j = 0; j < 9; ++j) {
                    if(board[i][j] == '.') {
                        continue;
                    }
                    else {
                        int c = board[i][j] - '1';
                        if(row[i][c] != false || col[j][c] != false || block[i - i % 3 + j / 3][c] != false) {
                            return false;
                        }
                        else {
                            row[i][c] = true;
                            col[j][c] = true;
                            block[i - i % 3 + j / 3][c] = true;
                        }
                    }
                }
            }
            return true;
        }
    }
};

int main() {
    const char str[][9] = {{'5', '3', '.', '.', '7', '.', '.', '.', '.'},
                           {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
                           {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
                           {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
                           {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
                           {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
                           {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
                           {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
                           {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};

    vector<vector<char> > board;
    for(unsigned i = 0; i < 9; ++i) {
        vector<char> temp;
        for(unsigned j = 0; j < 9; ++j) {
            temp.push_back(str[i][j]);
        }
        board.push_back(temp);
    }

    Solution test;
    cout << test.isValidSudoku(board) << endl;
    return 0;
}
