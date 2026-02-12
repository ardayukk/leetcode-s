class Solution {
public:
    int titleToNumber(string columnTitle) {
        int sum = 0;
        int n = columnTitle.size();
        
        for(int i = 0; i < n; i++){
            if(i == n - 1){
                sum += (columnTitle[i] - 'A' + 1);
            }
            else{
                sum += ((columnTitle[i] - 'A' + 1) * (pow(26,(n - i - 1))));
            }
            cout << sum << endl;
        }
        return sum;
    }
};