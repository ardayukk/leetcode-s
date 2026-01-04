class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int tot = 0;
        for(int i: nums){
            int a = countNumberOfDivisors(i); 
            if(a != -1){
                tot = tot + a;
            }
        }
        return tot;
    }
    int countNumberOfDivisors(int n){
        int total = 0;
        int nb = 0;
        for(int i = 1; i <= sqrt(n); i++){
            if(n % i == 0 && i != sqrt(n)){
                nb += 2;
                total += i;
                total += (n /i);
            }
            else if(n % i == 0){
                nb++;
                total += i;
            }
        }
        if(nb == 4){
            return total;
        }
        else{
            return -1;
        }
    }
};
