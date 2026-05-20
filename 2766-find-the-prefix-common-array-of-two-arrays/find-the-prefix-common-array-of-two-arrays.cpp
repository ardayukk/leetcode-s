class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        set<int> Aset;
        set<int> Bset;
        
        int n = A.size();
        vector<int> soln(n);
        
        Aset.insert(A[0]);
        Bset.insert(B[0]);
        soln[0] = (A[0] == B[0]);
        
        for(int i = 1; i < n; i++){
            
            int c = 0;
            bool b1 = false;
            if(Aset.find(B[i]) != Aset.end()) {c++; b1 = true;}
            if(Bset.find(B[i]) != Bset.end() && b1) c--;
            b1 = false;
            if(Bset.find(A[i]) != Bset.end()) {c++; b1 = true;}
            if(Aset.find(A[i]) != Aset.end() && b1) c--;
            if(c == 2 && A[i] == B[i])c--;
            else if(c== 0 && A[i] == B[i]) c++;
            soln[i] = soln[i - 1] + c;
            
            Aset.insert(A[i]);
            Bset.insert(B[i]);

        }
        return soln;

    }
};