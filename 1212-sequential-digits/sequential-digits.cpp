class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> sd;

        for (int first = 1; first <= 9; first++) {
            int number = first;

            for (int next = first + 1; next <= 9; next++) {
                number = number * 10 + next;
                sd.push_back(number);
            }
        }

        sort(sd.begin(), sd.end());

        auto left = lower_bound(sd.begin(), sd.end(), low);
        auto right = upper_bound(sd.begin(), sd.end(), high);

        return vector<int>(left, right);
    }
};