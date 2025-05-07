#include <iostream>
#include <vector>
using namespace std;

vector<int> majorityElement(int arr[], int n) {
    int count1 = 0, count2 = 0;
    int elem1 = -1, elem2 = -1;

    // First pass: find potential candidates
    for (int i = 0; i < n; i++) {
        if (arr[i] == elem1) {
            count1++;
        } else if (arr[i] == elem2) {
            count2++;
        } else if (count1 == 0) {
            elem1 = arr[i];
            count1 = 1;
        } else if (count2 == 0) {
            elem2 = arr[i];
            count2 = 1;
        } else {
            count1--;
            count2--;
        }
    }

    // Second pass: validate the candidates
    count1 = count2 = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == elem1) count1++;
        else if (arr[i] == elem2) count2++;
    }

    vector<int> ans;
    if (count1 > n / 3) ans.push_back(elem1);
    if (count2 > n / 3) ans.push_back(elem2);

    return ans;
}

int main() {
    int arr[6] = {11, 33, 33, 11, 33, 11};

    vector<int> res = majorityElement(arr, 6);

    for (int num : res) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
