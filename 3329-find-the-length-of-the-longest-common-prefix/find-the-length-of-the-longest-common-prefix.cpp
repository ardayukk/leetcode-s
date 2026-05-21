class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        set<int> set1(arr1.begin(), arr1.end());

        set<int> set2;
        for (int i = 0; i < arr2.size(); i++) {
            int a = arr2[i];
            while (a != 0) {
                set2.insert(a);
                a /= 10;
            }
        }

        int t = 0;

        for (auto a : set1) {
            int c = to_string(a).size();

            while (a != 0) {
                if (set2.find(a) != set2.end()) {
                    t = max(t, c);
                    break;
                }

                c--;
                a /= 10;
            }
        }

        return t;
    }
};