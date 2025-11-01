#include <queue>
using namespace std;

class MedianFinder {
public:
    priority_queue<int> leftMax; // max-heap (stores smaller half)
    priority_queue<int, vector<int>, greater<int>> rightMin; // min-heap (stores larger half)

    MedianFinder() {}

    void addNum(int num) {
        // Step 1: push to max heap first
        leftMax.push(num);

        // Step 2: make sure every left value <= every right value
        if (!leftMax.empty() && !rightMin.empty() && leftMax.top() > rightMin.top()) {
            rightMin.push(leftMax.top());
            leftMax.pop();
        }

        // Step 3: rebalance (sizes differ max by 1)
        if (leftMax.size() > rightMin.size() + 1) {
            rightMin.push(leftMax.top());
            leftMax.pop();
        }
        else if (rightMin.size() > leftMax.size()) {
            leftMax.push(rightMin.top());
            rightMin.pop();
        }
    }

    double findMedian() {
        if (leftMax.size() == rightMin.size()) {
            return (leftMax.top() + rightMin.top()) / 2.0;
        }
        return leftMax.top(); // left side always holds extra if odd
    }
};
