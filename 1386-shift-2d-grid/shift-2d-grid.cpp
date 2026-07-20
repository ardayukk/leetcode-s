class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int n = grid.size() * grid[0].size();
        vector<int> v(n);
        int j = 0;
        int l = 0;
        for(int i = k; i < n + k; i++){
            v[i % n] = grid[j][l];
            l++;
            if(l == grid[0].size()){
                l = 0;
                j++;
            }
        }

        // for(int i = 0; i < n; i++){
        //     cout << v[i] <<" ";
        // }
        // cout << endl;

        for(int i = 0; i < n; i++){
            cout << i << " ";
            grid[i / grid[0].size()][i % grid[0].size()] = v[i];
        }

        return grid;

    }
};