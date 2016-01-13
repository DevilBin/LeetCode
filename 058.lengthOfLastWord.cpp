/*************************************************************************
	> File Name: 058.lengthOfLastWord.cpp
	> Author: DevilBin 
	> Mail: whu.evil.binary@gmail.com 
	> Created Time: 2016/1/13 10:43:59
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
    int lengthOfLastWord(string s) {
        count = 0;
        for(i = static_cast<int>(s.size() - 1); i >= 0; --i) {
            if(isalpha(s[i])) 
                count++;
            else if(s[i] == ' ' && count == 0) 
                continue;
            else
                break;
        }
        if(i == -1 || s[i] == ' ')
            return count;
        else
            return 0;
    }
private:
    int i;
    int count;
};

int main() {
    string s = "world";
    
    Solution test;
    cout << test.lengthOfLastWord(s) << endl;
    return 0;
}
