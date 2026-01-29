class Solution {
public:
    long long minimumCost( string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        const long long INF = 1e18;
        int N = 26;

        // dist[i][j] = minimum cost to convert char i -> char j
        vector<vector<long long>> dist(N, vector<long long>(N, INF));

        // cost to convert a char to itself is 0
        for (int i = 0; i < N; i++) {
            dist[i][i] = 0;
        }

        // direct conversions
        for (int i = 0; i < (int)original.size(); i++) {
            int u = original[i] - 'a';
            int v = changed[i] - 'a';
            dist[u][v] = min(dist[u][v], (long long)cost[i]);
        }

        // Floyd–Warshall
        for (int k = 0; k < N; k++) {
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    if (dist[i][k] + dist[k][j] < dist[i][j]) {
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                }
            }
        }

        // calculate total cost
        long long ans = 0;
        for (int i = 0; i < (int)source.size(); i++) {
            int u = source[i] - 'a';
            int v = target[i] - 'a';

            if (dist[u][v] == INF) {
                return -1;  // impossible conversion
            }
            ans += dist[u][v];
        }

        return ans;
    }
};
