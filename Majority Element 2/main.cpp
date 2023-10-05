#include <vector>
#include <set>
#include <iostream>
class Solution {
public:
    static std::vector<int> majorityElement(std::vector<int>& nums) {
        std::multiset<int> set;
        std::vector<int> ret_val;
        std::size_t threshold = nums.size()/3;
        for(int num : nums)
            set.insert(num);
        for(auto it = set.begin(); it != set.end();){
            std::size_t count = set.count(*it);
            if(count > threshold)
                ret_val.push_back(*it);
            std::advance(it, count);
        }
        return ret_val;
    }
};

int main(){
    std::vector<int> test{3,2,3};
    std::vector<int> sol = Solution::majorityElement(test);
    for(auto n : sol)
        std::cout << n << '\n';
    return 0;
}