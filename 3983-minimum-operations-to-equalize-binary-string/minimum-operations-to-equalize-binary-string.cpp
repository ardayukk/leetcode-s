#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(string s, int k) {
        int n = (int)s.size();

        int startZeros = 0;
        for (char ch : s) if (ch == '0') startZeros++;

        set<int> unvisitedEven, unvisitedOdd;
        for (int z = 0; z <= n; z++) {
            if (z % 2 == 0) unvisitedEven.insert(z);
            else unvisitedOdd.insert(z);
        }

        if (startZeros % 2 == 0) unvisitedEven.erase(startZeros);
        else unvisitedOdd.erase(startZeros);

        queue<int> q;
        q.push(startZeros);

        int steps = 0;

        while (!q.empty()) {
            int layerSize = (int)q.size();

            while (layerSize--) {
                int z = q.front();
                q.pop();

                if (z == 0) return steps;

                int xMin = max(0, k - (n - z));
                int xMax = min(z, k);

                int minNextZ = z + k - 2 * xMax;
                int maxNextZ = z + k - 2 * xMin;

                set<int> &unvisited = ((minNextZ % 2 == 0) ? unvisitedEven : unvisitedOdd);

                auto it = unvisited.lower_bound(minNextZ);
                while (it != unvisited.end() && *it <= maxNextZ) {
                    int nextZ = *it;
                    q.push(nextZ);
                    it = unvisited.erase(it);
                }
            }

            steps++;
        }

        return -1;
    }
};