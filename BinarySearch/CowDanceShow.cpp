#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
	ll N, T;
	cin >> N >> T;
	vector<ll> v(N);
	for(int i = 0; i < N; i++) {
		cin >> v[i];
	}
	auto check = [&](int mid) {
		priority_queue<ll,vector<ll>,greater<ll>> pq;
		
		int curTime = 0;
		for(int i = 0; i < N; i++) {
			if(pq.size() == mid)
			{
				curTime = pq.top();
				pq.pop();
			}
			
			pq.push(curTime + v[i]);
		}
		while(pq.size())
		{
			curTime = pq.top();
			pq.pop();
		}
		return curTime <= T;
	};
	
	int lo = 1, hi = N, sol = 0;
	while(lo <= hi) {
		int mid = lo + (hi - lo) / 2;
		
		if(check(mid)) {
			hi = mid - 1;
			sol  = mid;
		}
		else {
			lo = mid + 1;
		}
	}
	cout << sol << endl;
}
