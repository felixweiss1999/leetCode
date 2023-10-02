#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

class Solution {
    static bool traverse_neighbor(std::vector<std::vector<char>> board, std::string_view word, long unsigned int x, long unsigned int y){
        if(word.empty()) return true;
        //not empty
        if(x >= board.size() || y >= board[0].size()) return false;
        //not empty and position correct
        if(word[0] == board[x][y]){ //not empty, position correct and match found!
            word.remove_prefix(1);
            board[x][y] = '\0'; //mark visited as success
            return traverse_neighbor(board, word, x+1, y) || traverse_neighbor(board, word, x-1, y) || traverse_neighbor(board, word, x, y+1) || traverse_neighbor(board, word, x, y-1);
        } 
        return false;//not empty, position correct but not right letter found!
    }
public:

    static bool exist(std::vector<std::vector<char>>& board, std::string word) {
        std::reverse(word.begin(), word.end());
        for(unsigned long int i = 0; i < board.size(); i++)
            for(unsigned long int j = 0; j < board[i].size(); j++){
                std::vector<std::vector<char>> local_board(board);
                if(traverse_neighbor(local_board, word, i, j))
                    return true;
            }
        return false;
    }
};

int main(){
    std::vector<std::vector<char>> board {{'A','B','C','E'},{'S','F','E','S'},{'A','D','E','E'}};
    std::cout << Solution::exist(board, "ABCESEEEFS");
    return 0;
}