#include <vector>
#include <iostream>
#include <set>
#define EMPTY 0
#define FRESH 1
#define ROTTEN 2
struct Orange{
    Orange(std::size_t _x, std::size_t _y) : x(_x), y(_y){}
    bool operator<(const Orange& other) const
    {
        if (x < other.x)
            return true;
        if (x == other.x && y < other.y)
            return true;
        return false;
    }
    std::size_t x;
    std::size_t y;
};

class Solution {
    static bool coord_valid(std::vector<std::vector<std::size_t>>& grid, std::size_t i, std::size_t j){
        if(i >= grid.size() || j >= grid[0].size())
            return false;
        return true;
    }
    static void add_fresh_neighbors_to_rotting(std::vector<std::vector<std::size_t>>& grid, std::size_t i, std::size_t j, std::set<Orange>& rotting_oranges){
        if(coord_valid(grid, i-1, j))
            if(grid[i-1][j] == FRESH)
                rotting_oranges.emplace(i-1, j);
        if(coord_valid(grid, i+1, j))
            if(grid[i+1][j] == FRESH)
                rotting_oranges.emplace(i+1, j);
        if(coord_valid(grid, i, j-1))
            if(grid[i][j-1] == FRESH)
                rotting_oranges.emplace(i, j-1);
        if(coord_valid(grid, i, j+1))
            if(grid[i][j+1] == FRESH)
                rotting_oranges.emplace(i, j+1);
    }
public:
    static int orangesRotting(std::vector<std::vector<int>>& _grid) {
        std::set<Orange> prev_rotting_oranges, next_rotting_oranges;
        int minute = 0;
        std::vector<std::vector<std::size_t>> grid;
        for(auto row : _grid){
            grid.push_back(std::vector<std::size_t>());
            for(auto col : row)
                grid.back().push_back((std::size_t) col );
        }
        /*first, scan for fouled oranges, fill fouling_oranges on the way. 
        then, execute for loop (minutes): in each iteration, each fouling orange 
            adds its non-fouling neighbors to the set. 
            deletes itself from the set
        as soon as no more fouling oranges, check if any fresh oranges left, return accordingly*/
        for(std::size_t i = 0; i < grid.size(); i++)
            for(std::size_t j = 0; j < grid[0].size(); j++)
                if(grid[i][j] == ROTTEN)
                    add_fresh_neighbors_to_rotting(grid, i, j, prev_rotting_oranges);
        while(!prev_rotting_oranges.empty()){
            for(Orange orange : prev_rotting_oranges){ 
                add_fresh_neighbors_to_rotting(grid, orange.x, orange.y, next_rotting_oranges); // we need to later remove the ones erroneously added!!
                grid[orange.x][orange.y] = ROTTEN;
            }
            for(Orange orange : prev_rotting_oranges)
                next_rotting_oranges.erase(orange);
            prev_rotting_oranges = std::move(next_rotting_oranges);
            next_rotting_oranges.clear();
            minute++;
        }
        for(auto row : grid)
            for(auto col : row)
                if(col == FRESH)
                    return -1;
        return minute;
    }
};

int main(){
    std::vector<std::vector<int>> grid{{2,2},{1,1},{0,0},{2,0}};
    std::cout << Solution::orangesRotting(grid) << '\n';
}