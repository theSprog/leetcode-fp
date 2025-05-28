#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
  public:
    vector<int> twoSum(vector<int>& nums, int target) {
        using Value = int;
        using Index = int;
        std::unordered_map<Value, Index> mp;

        for (int i = 0; i < nums.size(); i++) {
            if (mp.count(target - nums[i])) {
                return {i, mp[target - nums[i]]};
            }
            mp[nums[i]] = i;
        }

        return {};
    }
};

