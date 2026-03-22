class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        if(checkeq(mat, target)) return true;

        for(int i = 0; i < 3; i++){
            rotate(mat);
            if(checkeq(mat,target)) return true;
        }

        return false;
    }

    bool checkeq(vector<vector<int>>& a, vector<vector<int>>& b){
        int n = a.size();
        int m = a[0].size();
        if(n != b.size() || m != b[0].size()){
            return false;
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m;j++){
                if(a[i][j] != b[i][j]) return false;
            }
        }
        return true;
    }

    void rotate(vector<vector<int>>& a){
        transpose(a);
        colRev(a);
    }

    // Source - https://stackoverflow.com/a/49445850
    // Posted by Matthias Grün, modified by community. See post 'Timeline' for change history
    // Retrieved 2026-03-22, License - CC BY-SA 3.0

    void transpose(vector<vector<int> > &b)
    {
        if (b.size() == 0)
            return;

        vector<vector<int> > trans_vec(b[0].size(), vector<int>());

        for (int i = 0; i < b.size(); i++)
        {
            for (int j = 0; j < b[i].size(); j++)
            {
                trans_vec[j].push_back(b[i][j]);
            }
        }

        b = trans_vec;    // <--- reassign here
    }

    void colRev(vector<vector<int>>& a){
        int n = a.size();
        for(int i = 0; i < a[0].size(); i++){
            for(int j = 0; j < n / 2; j++){
                swap(a[j][i], a[n - j - 1][i]);
            }
        }
    }   

};