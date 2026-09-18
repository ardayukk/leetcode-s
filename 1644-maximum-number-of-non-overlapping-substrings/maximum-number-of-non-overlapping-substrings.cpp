class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n = s.size();

        vector<int> first(26, n);
        vector<int> last(26, -1);

        for (int i = 0; i < n; i++) {
            int c = s[i] - 'a';
            first[c] = min(first[c], i);
            last[c] = i;
        }

        vector<pair<int, int>> intervals;

        for (int c = 0; c < 26; c++) {
            if (last[c] == -1) continue;

            int begin = first[c];
            int end = last[c];
            bool valid = true;

            for (int i = begin; i <= end; i++) {
                int current = s[i] - 'a';

                if (first[current] < begin) {
                    valid = false;
                    break;
                }

                end = max(end, last[current]);
            }

            if (valid) {
                intervals.push_back({begin, end});
            }
        }

        sort(intervals.begin(), intervals.end(),
             [](const auto& a, const auto& b) {
                 if (a.second != b.second)
                     return a.second < b.second;

                 return a.first > b.first;
             });

        vector<string> result;
        int previousEnd = -1;

        for (const auto& [begin, end] : intervals) {
            if (begin > previousEnd) {
                result.push_back(
                    s.substr(begin, end - begin + 1)
                );

                previousEnd = end;
            }
        }

        return result;
    }
};