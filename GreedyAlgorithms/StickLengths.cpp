#include <bits/stdc++.h>
using namespace std;
int n;
int main() {
    cin >> n;
    vector<int> nums;
    for (int i  = 0; i < n; i++) {
        int a;
        cin >> a;
        nums.push_back(a);
    }
    sort(nums.begin(), nums.end());
    /*for (int i = 0; i < n; i++) {
        cout << nums[i] << ' ';
    }*/
    int median = nums[n/2];
    int answer;
    for (int i = 0; i < n; i++) {
        int diff = abs(median-nums[i]);
        answer += diff;
    }
    cout << answer << endl;
    return 0;
}
