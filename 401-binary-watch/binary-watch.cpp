class Solution {
public:
    vector<int> hourPossibilities = {8,4,2,1};
    vector<int> minutePossibilities = {32,16,8,4,2,1};

    void combSum(const vector<int>& vec, int start, int n,
                 int curSum, vector<int>& result) {
        if (n == 0) {
            result.push_back(curSum);
            return;
        }
        for (int i = start; i < (int)vec.size(); i++) {
            combSum(vec, i + 1, n - 1, curSum + vec[i], result);
        }
    }

    vector<int> choosen(const vector<int>& vec, int n) {
        vector<int> result;
        combSum(vec, 0, n, 0, result);
        sort(result.begin(), result.end());
        return result;
    }

    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> finalVec;

        for (int usedForHour = turnedOn; usedForHour >= 0; usedForHour--) {
            int usedForMinute = turnedOn - usedForHour;

            if (usedForHour > 4) continue;
            if (usedForMinute > 6) continue;

            vector<int> hours = choosen(hourPossibilities, usedForHour);
            vector<int> minutes = choosen(minutePossibilities, usedForMinute);

            // filter invalid times
            hours.erase(remove_if(hours.begin(), hours.end(),
                                  [](int h){ return h > 11; }),
                        hours.end());
            minutes.erase(remove_if(minutes.begin(), minutes.end(),
                                    [](int m){ return m > 59; }),
                          minutes.end());

            int hourCount = (int)hours.size();
            int minuteCount = (int)minutes.size();
            if (hourCount == 0 || minuteCount == 0) continue;

            vector<string> strVec(hourCount * minuteCount, "");

            for (int i = 0; i < hourCount; i++) {
                for (int j = 0; j < minuteCount; j++) {
                    strVec[i * minuteCount + j] = to_string(hours[i]) + ":";
                }
            }

            for (int i = 0; i < hourCount; i++) {
                for (int j = 0; j < minuteCount; j++) {
                    if (minutes[j] < 10) {
                        strVec[i * minuteCount + j] += "0" + to_string(minutes[j]);
                    } else {
                        strVec[i * minuteCount + j] += to_string(minutes[j]);
                    }
                }
            }

            for (auto& a : strVec) finalVec.push_back(a);
        }

        return finalVec;
    }
};
