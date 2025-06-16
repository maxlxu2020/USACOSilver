#include <bits/stdc++.h>
using namespace std;
int n, k, b;
int best = INT32_MAX;
int main() {
    cin >> n >> k >> b;
    vector<bool> lightsoff(n);
    vector<int> prefix(n);
    for (int i = 0; i < b; i++) {
        int a;
        cin >> a;
        lightsoff[a] = true;
    }
    for (int i = 0; i < n; i++) {
        prefix[i] = prefix[i-1] + lightsoff[i];
    }
    for (int i = 0; i < n-k; i++) {
        best = min(best, prefix[i+k]-prefix[i]);
    }
    cout << best;
    
}