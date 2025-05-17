#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

class Solution {
public:
    // Find index of the Previous Smaller Element (to the left)
    vector<int> leftSmallest(vector<int>& arr) {
        stack<int> s;
        int n = arr.size();
        vector<int> ans(n);

        for (int i = 0; i < n; i++) {
            while (!s.empty() && arr[s.top()] >= arr[i]) {
                s.pop();
            }

            ans[i] = (s.empty()) ? -1 : s.top();
            s.push(i);
        }

        return ans;
    }

    // Find index of the Next Smaller Element (to the right)
    vector<int> rightSmallest(vector<int>& arr) {
        stack<int> s;
        int n = arr.size();
        vector<int> ans(n);

        for (int i = n - 1; i >= 0; i--) {
            while (!s.empty() && arr[s.top()] >= arr[i]) {
                s.pop();
            }

            ans[i] = (s.empty()) ? n : s.top();
            s.push(i);
        }

        return ans;
    }

    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> ls = leftSmallest(heights);
        vector<int> rs = rightSmallest(heights);

        int maxArea = 0;
        for (int i = 0; i < n; i++) {
            int width = rs[i] - ls[i] - 1;
            int area = heights[i] * width;
            maxArea = max(maxArea, area);
        }

        return maxArea;
    }
};

int main() {
    Solution sol;

    // Test case
    vector<int> heights = {2, 1, 5, 6, 2, 3};

    int maxArea = sol.largestRectangleArea(heights);

    cout << "Largest Rectangle Area: " << maxArea << endl;

    return 0;
}
