class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> freq;
        for(int i=0;i<n;i++) freq[nums[i]]++;
        priority_queue<pair<int,int>> pq;
        for( auto it: freq)
        {
            pq.push({it.second,it.first});
        }

        vector<int> ans;
        for(int i=1;i<=k;i++)
        {
            auto it= pq.top();
            pq.pop();
            ans.push_back({it.second});
        }

return ans;
    }
};
