class Solution {
public:
    bool isRotatable(span<int> original, vector<int>& sub) {
        int n = sub.size();

        int drops = 0;

        for (int i = 0; i < n; i++) {
            if (sub[i] > sub[(i + 1) % n]) {
                drops++;
            }
        }

        if (drops > 1) return false;

        vector<int> sortedSub = sub;
        sort(sortedSub.begin(), sortedSub.end());

        for (int i = 0; i < n; i++) {
            if (sortedSub[i] != original[i]) return false;
        }

        return true;
    }

    int sortableIntegers(vector<int>& nums) {
        vector<int> divisors;
        int n = nums.size();

        vector<int> numSorted = nums;
        sort(numSorted.begin(), numSorted.end());

        for (int i = 1; i * i <= n; ++i) {
            if (n % i == 0) {
                divisors.push_back(i);

                if (i * i != n) {
                    divisors.push_back(n / i);
                }
            }
        }

        int a = 0;

        for (int& divisor : divisors) {
            bool doIadd = true;

            for (int i = 0; i < n / divisor; i++) {
                vector<int> sub(
                    nums.begin() + i * divisor,
                    nums.begin() + (i + 1) * divisor
                );

                if (!isRotatable(
                    span<int>(numSorted.data() + i * divisor, divisor),
                    sub
                )) {
                    doIadd = false;
                    break;
                }
            }

            if (doIadd) {
                a += divisor;
            }
        }

        return a;
    }
};