#include <string>
#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

class Solution
{
    inline static std::unordered_map<std::string, int> frequency;
    static bool custom_compare(const std::string& str1, const std::string& str2){
        if(Solution::frequency[str1] != Solution::frequency[str2])
            return Solution::frequency[str1] > Solution::frequency[str2];
        else    
            return str1 < str2;
    }
public:
    static std::vector<std::string> topKFrequent(std::vector<std::string> &words, int k)
    {
        frequency.clear();
        for (auto word : words) 
            frequency[std::move(word)]++;
        std::vector<std::string> ret_val;
        for (auto pair : frequency)
            ret_val.emplace_back(pair.first);
        std::sort(ret_val.begin(), ret_val.end(), custom_compare);
        ret_val.resize(k);
        return ret_val;
    }
    
};


int main()
{
    std::vector<std::string> v {"the","day","is","sunny","the","the","the","sunny","is","is"};
    Solution::topKFrequent(v, 4);
    return 0;
}