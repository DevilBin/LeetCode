/*************************************************************************
	> File Name: 079.wordSearch.cpp
	> Author: DevilBin 
	> Mail: whu.evil.binary@gmail.com 
	> Created Time: 2016/2/27 11:08:54
 ************************************************************************/

#include <iostream>
#include <iomanip>
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
const int N = 3;

class Solution {
public:
    bool exist(vector<vector<char> > & board, string word) {
        vector<vector<bool> > visited(board.size(), vector<bool>(board[0].size(), false));
        if(board.size() == 0) {
            return false;
        }
        for(int i = 0; i < static_cast<int>(board.size()); ++i) {
            for(int j = 0; j < static_cast<int>(board[i].size()); ++j) {
                if(digAround(board, visited, i, j, word, 0)) return true;
            }
        }
        return false;
    }
    bool digAround(
        vector<vector<char> > & board, 
        vector<vector<bool> > & visited, 
        int row, 
        int col, 
        string word, 
        unsigned index) {
            if(word.size() == index) 
                return true;
            if(
                row < 0 || 
                col < 0 ||
                row >= static_cast<int>(board.size()) ||
                col >= static_cast<int>(board[row].size()) ||
                visited[row][col] ||
                board[row][col] != word[index]) {
                return false;
            }
            visited[row][col] = true;
            if(digAround(board, visited, row - 1, col, word, index + 1)) return true;
            if(digAround(board, visited, row, col + 1, word, index + 1)) return true;
            if(digAround(board, visited, row + 1, col, word, index + 1)) return true;
            if(digAround(board, visited, row, col - 1, word, index + 1)) return true;
            visited[row][col] = false;
            return false;
    }
};

int main() {
    const char arr[N][N + 1] = {{'A', 'B', 'C', 'E'},
                                {'S', 'F', 'C', 'S'},
                                {'A', 'D', 'E', 'E'}};
    vector<vector<char> > board;
    
    for(unsigned i = 0; i < N; ++i) {
        vector<char> temp;
        for(unsigned j = 0; j < N + 1; ++j) {
            temp.push_back(arr[i][j]);
        }
        board.push_back(temp);
    }

    Solution test;
    cout << test.exist(board, "ABCESCFSADEE") << endl;
    return 0;
}
