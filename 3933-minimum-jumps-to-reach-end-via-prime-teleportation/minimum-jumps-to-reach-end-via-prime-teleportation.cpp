class Solution {
public:
    int minJumps(vector<int>& nums) {
        unordered_map<int,set<int>> um;

        for(int i = 0; i < nums.size(); i++){
            int num = nums[i];

            while(num != 1){
                int p = getPrime(num);
                um[p].insert(i);

                while(num % p == 0){
                    num /= p;
                }
            }
        }

        queue<pair<int,int>> q;
        vector<bool> visited(nums.size(), false);

        q.push({0,0});
        visited[0] = true;

        while(!q.empty()){
            pair<int,int> qfront = q.front();
            q.pop();

            int idx = qfront.first;
            int jumps = qfront.second;

            if(idx == nums.size() - 1){
                return jumps;
            }

            if(is_prime(nums[idx])){
                int p = nums[idx];

                for(auto& c: um[p]){
                    if(!visited[c]){
                        visited[c] = true;
                        q.push({c, jumps + 1});
                    }
                }

                um[p].clear();
            }

            if(idx + 1 < nums.size() && !visited[idx + 1]){
                visited[idx + 1] = true;
                q.push({idx + 1, jumps + 1});
            }

            if(idx - 1 >= 0 && !visited[idx - 1]){
                visited[idx - 1] = true;
                q.push({idx - 1, jumps + 1});
            }
        }

        return -1;
    }

    int getPrime(int n){
        for(int i = 2; i * i <= n; i++){
            if(n % i == 0){
                return i;
            }
        }
        return n;
    }

    bool is_prime(int n) {
        if (n < 2) return false;
        if (n == 2) return true;
        if (n % 2 == 0) return false;

        for (int i = 3; i * i <= n; i += 2) {
            if (n % i == 0) return false;
        }

        return true;
    }
};