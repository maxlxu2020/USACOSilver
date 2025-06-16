#include <bits/stdc++.h>
using namespace std;
int n, x;
vector<int> prefix;
int counter = 0;
int main()
{
    cin >> n >> x;
    prefix.resize(n);
    prefix[-1] = 0;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        prefix[i] = prefix[i-1] + a;
    }
    int left = 0;
    for (int right = 0; right <= n; right++) {
        left = 0;
        while (prefix[right]-prefix[left-1] > x && left <= right) {
            left++;
        }
        if (prefix[right]-prefix[left-1] == x) {
            counter++;
        }
    }
    cout << counter;
    return 0;
}