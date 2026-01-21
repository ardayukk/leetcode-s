class Solution {
public:
    int maxProduct(int n) {
        vector<int> a;
        while(n > 0){
            a.push_back(n%10);
            n/= 10;
        }
        sort(a.begin(), a.end(), greater<>());
        return a[0] * a[1];
    }
};