class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        int total = 0;
        priority_queue<int> pq;
        for(auto& i: nums){
            total += i;
            pq.push(i);
        }
        vector<int> ret;
        int totalcpy = total;
        
        while(pq.size() > 0 && totalcpy * 2 >= total){
            ret.push_back(pq.top());
            totalcpy -= pq.top();
            pq.pop();
        }
        return ret;
    }
};