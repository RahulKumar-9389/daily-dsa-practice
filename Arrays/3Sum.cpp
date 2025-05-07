#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> threeSum(vector<int> &arr, int target)
{
    int n = arr.size();
    vector<vector<int>> ans;

    if (n < 3)
        return ans;

    sort(arr.begin(), arr.end());

    for (int i = 0; i < n - 2; i++)
    {
        // Skip duplicate elements for 'i'
        if (i > 0 && arr[i] == arr[i - 1])
            continue;

        int j = i + 1, k = n - 1;

        while (j < k)
        {
            int sum = arr[i] + arr[j] + arr[k];

            if (sum == target)
            {
                ans.push_back({arr[i], arr[j], arr[k]});
                j++;
                k--;

                // Skip duplicates for 'j' and 'k'
                while (j < k && arr[j] == arr[j - 1])
                    j++;
                while (j < k && arr[k] == arr[k + 1])
                    k--;
            }
            else if (sum < target)
            {
                j++;
            }
            else
            {
                k--;
            }
        }
    }

    return ans;
}

int main()
{
    vector<int> arr = {-1, 0, 1, 2, -1, -4};
    int target = 0;

    vector<vector<int>> res = threeSum(arr, target);

    for (auto triplet : res)
    {
        for (int num : triplet)
        {
            cout << num << " ";
        }
        cout << "\n";
    }

    return 0;
}
