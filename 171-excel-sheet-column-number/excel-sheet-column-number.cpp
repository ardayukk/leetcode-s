class Solution {
public:
    int titleToNumber(string columnTitle) {
        int sum = 0;
        int n = columnTitle.size();
        
        for(int i = 0; i < n; i++){
            sum += ((columnTitle[i] - 'A' + 1) * (pow(26,(n - i - 1))));
        }
        return sum;
    }
};