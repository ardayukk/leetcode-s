class Solution {
public:
    int candy(vector<int>& ratings) {
        int* candy = new int[ratings.size()];
        int* candy2 = new int[ratings.size()];
        for(int i =0; i < ratings.size(); i++){
            candy[i] = 1;
            candy2[i] = 1;
        }
        for(int i = 1; i < ratings.size(); i++){
            if(ratings[i] > ratings[i - 1]) candy[i] = candy[i-1] + 1;
            else candy[i] = 1;
        }
        
        for(int i = ratings.size() -2; i >= 0; i--){
            if(ratings[i] > ratings[i + 1]) candy2[i] = candy2[i + 1] + 1;
            else candy2[i] = 1;
        }
        int sum = 0;
        for(int i = 0; i < ratings.size(); i++){
            sum += max(candy[i], candy2[i]);
        }
        delete[] candy;
        delete[] candy2;
        return sum;
    }
};