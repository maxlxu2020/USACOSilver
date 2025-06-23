#include <bits/stdc++.h>
using namespace std;
long long haybales[50001];
bool check(int n, int k, int r){
    int idx = 0;
    int used_idx = 0;
    bool used = true;
    long long pos;
    while (used_idx < k && used == true){
        used = false;
        pos = haybales[idx]+2*r;
        for (int i = idx; i < n; i++){
            if (haybales[i] > pos){
                idx = i;
                used_idx++;
                used = true;
                break;
            }
        }
    }
    if (pos < haybales[n-1]){
        return false;
    }
    return true;
}
int main() {
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++){
        cin >> haybales[i];
    }
    sort (haybales, haybales+n);
    int l, r, mid;
    l = 1;
    r = haybales[n-1];
    int min_power = 10000;
    while (l <= r){
        mid = (l+r)/2;
        if (check(n, k, mid)){
            r = mid-1;
            min_power = mid;
        }
        else {
            l = mid+1;
        }
    }
    cout << min_power;
    return 0;
}
