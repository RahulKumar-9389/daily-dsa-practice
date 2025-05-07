#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> fourSum(vector<int>& nums, int target) {
    int n = nums.size();
    vector<vector<int>> res;

    if (n < 4) return res;

    sort(nums.begin(), nums.end());

    for (int i = 0; i < n - 3; i++) {
        // Skip duplicates for i
        if (i > 0 && nums[i] == nums[i - 1]) continue;

        for (int j = i + 1; j < n - 2; j++) {
            // Skip duplicates for j
            if (j > i + 1 && nums[j] == nums[j - 1]) continue;

            int left = j + 1, right = n - 1;

            while (left < right) {
                long long sum = (long long)nums[i] + nums[j] + nums[left] + nums[right];

                if (sum == target) {
                    res.push_back({nums[i], nums[j], nums[left], nums[right]});
                    left++;
                    right--;

                    // Skip duplicates for left and right
                    while (left < right && nums[left] == nums[left - 1]) left++;
                    while (left < right && nums[right] == nums[right + 1]) right--;

                } else if (sum < target) {
                    left++;
                } else {
                    right--;
                }
            }
        }
    }

    return res;
}

int main() {
    vector<int> arr = {1, 0, -1, 0, -2, 2};
    int target = 0;

    vector<vector<int>> res = fourSum(arr, target);

    for (const auto& quad : res) {
        for (int num : quad) {
            cout << num << " ";
        }
        cout << "\n";
    }

    return 0;
}
