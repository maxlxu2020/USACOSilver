#include <bits/stdc++.h>
using namespace std;
int n;

int main() {
    cin >> n;
    vector<int> cows;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        cows.push_back(a);
    }
    sort(cows.begin(), cows.end());
    reverse(cows.begin(), cows.end());
    int counter = 0;
    for (int i = 0; i < n; i++) {
        if (cows[i] >= i) {
            counter++;
        }
        else{
            break;
        }
    }
    cout << counter;
}