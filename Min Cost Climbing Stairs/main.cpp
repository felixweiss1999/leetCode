#include <iostream>
#include <vector>

class Solution {
public:
        //inline static int walk_calls = 0;
    static void walk(std::vector<int>& cost, std::vector<int>& min_total_cost, int pos, int cost_to_get_here){
        //walk_calls++;
        if(pos >= static_cast<int>(cost.size()))
        {
            min_total_cost.back() = std::min(cost_to_get_here, min_total_cost.back());
            return;
        }
        
        if(cost_to_get_here + cost[pos] >= min_total_cost[pos])
            return;
        else
            min_total_cost[pos] = cost_to_get_here + cost[pos];
        walk(cost, min_total_cost, pos+2, cost_to_get_here + cost[pos]);
        walk(cost, min_total_cost, pos+1, cost_to_get_here + cost[pos]);
            
    }
    static int minCostClimbingStairs(std::vector<int>& cost) {
        std::vector<int> min_total_cost(cost.size()+1, INT32_MAX);
        walk(cost, min_total_cost, 1, 0);
        walk(cost, min_total_cost, 0, 0);
        return min_total_cost.back();
    }

    //more elegent:
    int minCostClimbingStairsElegant(std::vector<int>& cost) {
        int n = cost.size();
        int prev1 = 0, prev2 = 0;

        for (int i = 2; i <= n; i++) {
            int current_cost = std::min(prev1 + cost[i - 1], prev2 + cost[i - 2]);
            prev2 = prev1;
            prev1 = current_cost;
        }

        return prev1;
    }
};

int main()
{
    std::vector<int> vec {1,2,3,0,10,55};
    int result = Solution::minCostClimbingStairs(vec);
    //int count = Solution::walk_calls;
}