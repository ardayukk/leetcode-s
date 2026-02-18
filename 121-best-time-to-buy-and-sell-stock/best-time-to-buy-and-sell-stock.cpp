class Solution {
public:
    int maxProfit(vector<int>& prices) {
        unordered_map<int,int> freq;
        priority_queue<int> pq;
        int m = 0;
        for(int i = 0; i < prices.size(); i++){
            freq[prices[i]]++;
            if(freq[prices[i]] == 1){
                pq.push(prices[i]);
            }
        }
        for(int i = 0; i < prices.size(); i++){
            freq[prices[i]]--;
            while(pq.size() != 0 && freq[pq.top()] == 0) pq.pop();
            if(pq.size() != 0)
            m = max(pq.top() - prices[i], m);
        }
        return m;
    }
};