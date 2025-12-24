#include <queue>
using namespace std;

class RecentCounter {
public:
    queue<int> q;

    RecentCounter() {
        // queue starts empty
    }

    int ping(int t) {
        q.push(t);

        // remove calls older than t - 3000
        while (!q.empty() && q.front() < t - 3000) {
            q.pop();
        }

        return q.size();
    }
};
