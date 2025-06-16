#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> prefix;
int counter = 0;
int main() {
    cin >> n;
    prefix.resize(n);
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        prefix[i] = (prefix[i-1] + (a%n))%5;
    }
    
    cout << endl;
    int left = 0;
    for (int right = 0; right < n; right++) {
        int left = 0;
        while (prefix[right] != prefix[left-1] && left < right) {
            left++;
        }
        if (prefix[right] == prefix[left-1]) {
            counter++;
        }
    }
    cout << counter;
}