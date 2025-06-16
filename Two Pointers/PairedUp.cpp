#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> cows;
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        for (int i = 0; i < a; i++) {
            cows.push_back(b);
        }
    }
    
    vector<int> sums;
    int left = 0, right = cows.size()-1;
    while (left < right) {
        sums.push_back(cows[left] + cows[right]);
        left++;
        right--;
    }
    cout << *max_element(sums.begin(), sums.end());
    return 0;
}