#include <bits/stdc++.h>
using namespace std;
int n, x;
vector<int> nums;
int sum = 0;
int main()
{
    cin >> n >> x;
    vector<int> prefix(n);
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        nums.push_back(a);
        prefix[i] = prefix[i-1] + nums[i];
    }
    
    int left = 0;
    for (int right = 0; right < n; right++) {
        while (left < right && prefix[right]-prefix[left] > x) {
            left++;
        }
        if (prefix[right]-prefix[left] == x) {
            sum++;
        }
    }
    for (int i = 0; i < n; i++) {
        if (nums[i] == x) {
            sum++;
        }
    }
    cout << sum;
    return 0;
}