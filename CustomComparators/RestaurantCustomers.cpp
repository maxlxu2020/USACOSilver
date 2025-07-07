#include <bits/stdc++.h>
using namespace std;
int n;

int main() {
    cin >> n;
    vector<pair<int, int>> times;

    for (int i = 0; i < n; i++) {
        int start, end;
        cin >> start >> end;
        times.push_back(make_pair(start, 1));
        times.push_back(make_pair(end+1, -1));
    }
    sort(times.begin(), times.end());

    vector<int> changes(2*n);
    int pos = 0;
    int cur = 0;
    for (int i = 0; i < 2*n; i++) {
        if (i == 0) {
            times[i].first = 0;
        } else if(times[i].first > cur) {
            pos++;
            cur = times[i].first;
        }
        changes[pos+1] += times[i].second;
    }

    vector<int> prefix(2*n+1);
    for (int i = 0; i < 2*n+1; i++) {
        prefix[i] = changes[i-1] + prefix[i-1];
    }
    int maxs = *max_element(prefix.begin(), prefix.end());
    cout << maxs;
}
