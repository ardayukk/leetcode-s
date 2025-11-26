class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {

        int* newArr = new int[amount + 1];

        for(int i = 0; i < amount + 1; i++){
            newArr[i] = INT_MAX - 1;
        }
        newArr[0] = 0;

        for(int i = 0; i < coins.size(); i++){
            if(coins[i] > amount){
                continue;
            }
            newArr[coins[i]] = 1;
        }

        for(int i = 0; i < coins.size(); i++){
            for(int j = coins[i]; j < amount + 1; j++){
                newArr[j] = min(newArr[j-coins[i]] + 1, newArr[j]);
            }
        }
        if(newArr[amount] == INT_MAX - 1){
            return -1;
        }
        return newArr[amount];
    }
};