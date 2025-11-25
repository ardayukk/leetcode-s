class Solution {
public:
    int climbStairs(int n) {
        if(n <= 2){
            return n;
        }
        int* A = new int[n];
        A[0] = 1;
        A[1] = 2;
        for(int i = 2; i < n; i++){
            A[i] = A[i-1] + A[i-2];
        }
        return A[n-1];
    }
};