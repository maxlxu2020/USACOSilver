#include <bits/stdc++.h>
using namespace std;
int n, m, k;
int main() {
    cin >> n >> m >> k;
    vector<int> applicant, apartments;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        applicant.push_back(a);
    }
    for (int i = 0; i < m; i++) {
        int a;
        cin >> a;
        apartments.push_back(a);
    }
    sort(applicant.begin(), applicant.end());
    sort(apartments.begin(), apartments.end());
    

    int i = 0;
    int j = 0;
    int ans = 0;
    while (i < n && j < m) {
        if (abs(applicant[i]-apartments[j]) <= k) {
            i++;
            j++;
            ans++;
        }
        else if(applicant[i] - apartments[j] > k) {
            j++;
        }
        else {
            i++;
        }
    }
    cout << ans << endl;
}