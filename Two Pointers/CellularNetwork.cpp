#include <bits/stdc++.h>
#include <vector>
using namespace std;
int n, m;
vector<int> cities;
vector<int> towers;

int main() {
    cin >> n >> m;
    vector<vector<int>> distance(n);
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        cities.push_back(a);
    }
    for (int j = 0; j < m; j++) {
        int a;
        cin >> a;
        towers.push_back(a);
    }
    for (int i = 0; i < cities.size(); i++) {
        for (int j : towers) {
            distance[i].push_back(abs(j-cities[i]));
        }
    }
    vector<int> minimums;
    for (vector<int> i : distance) {
        minimums.push_back(*min_element(i.begin(), i.end()));
    }
    cout << *max_element(minimums.begin(), minimums.end());
}