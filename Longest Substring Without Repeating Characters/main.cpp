#include <string>
#include <unordered_map>

class Solution {
public:
    static int lengthOfLongestSubstring(std::string s) {
        std::unordered_map<char, bool> map;
        int len = 0, max_len = 0;
        for (char c : s){
            if(map.count(c) > 0){ //detected duplicate!
                max_len = std::max(len, max_len);
                len = 0;
                map.clear();
            }
            map.insert({c, true});
            len++;
        }
        return std::max(len, max_len);
    }
};

int main(){
    printf("%d\n", Solution::lengthOfLongestSubstring("kufiztfouzfouizgoiuhpkughgdztea6rdutzdfolu"));
    return 0;
}