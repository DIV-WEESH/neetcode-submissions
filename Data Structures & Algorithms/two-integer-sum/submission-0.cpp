class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> freq;
        for(int i=0;i<nums.size();i++)
        {
            if(freq.find(nums[i]) != freq.end())return {freq[nums[i]],i};

            freq[target-nums[i]]=i;
        }
        return {};
    }
};
