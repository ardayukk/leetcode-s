class Solution {
public:
    int minOperations(vector<int>& nums) {
        stack<int> st;
        int n = 0;


        for(int x: nums){
            while(!st.empty() && st.top()> x){
                st.pop();
            }
            if(x == 0) continue;

            if(st.empty() || st.top() < x){
                st.push(x);
                n++;
            }
        }

       
        return n;
    }
};


// 1 2 1 3 2 1 2 2 2 2
// 0 2 0 3 2 0 2 2 2 2

// 0 0 0 3 2 0 2 2 2 2 
// 0 0 0 0 2 0 2 2 2 2 