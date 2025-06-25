#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct order {
	ll a, b, c;
};

void solve() {
	ll n, c, m;
	cin >> n >> c >> m;
	vector<order> orders;
	for (ll i = 0; i < n; i++) {
		order o;
		cin >> o.a >> o.b >> o.c;
		orders.push_back(o);
	}
	ll minMoonies = 0;
	ll l = 0, r = c+m-2;
	while (l <= r) {
		ll mid = (r-l)/2 + l; // moonies spent

		ll minX = 1, maxX = c;
		bool impossible = false;
		for (order o : orders) {
			ll optX;
			if (o.a >= o.b) {
				optX = c-min(mid, c-1); // minX, maxY

				minX = max(optX, minX);

				ll otherX = -1;
				ll lc = optX, rc = c-(mid-min(mid, m-1));
				while (lc <= rc) {
					ll midc = (rc-lc)/2 + lc; // new time spent for 1 cookie
					if (midc*o.a + (m-(mid-(c-midc)))*o.b <= o.c) {
						otherX = midc;
						lc = midc+1;
					}
					else {
						rc = midc-1;
					}
				}

				if (otherX != -1) {
					maxX = min(otherX, maxX);
				}
				else {
					impossible = true;
					break;
				}
			}
			else {
				optX = c-(mid-min(mid, m-1)); // maxX, minY

				maxX = min(optX, maxX);

				ll otherX = -1;
				ll lc = c-min(mid, c-1), rc = optX;
				while (lc <= rc) {
					ll midc = (rc-lc)/2 + lc; // new time spent for 1 cookie
					if (midc*o.a + (m-(mid-(c-midc)))*o.b <= o.c) {
						otherX = midc;
						rc = midc-1;
					}
					else {
						lc = midc+1;
					}
				}

				if (otherX != -1) {					
					minX = max(otherX, minX);
				}
				else {
					impossible = true;
					break;
				}
			}
		}

		if (maxX >= minX && !impossible) {
			minMoonies = mid;
			r = mid-1;
		}
		else {
			l = mid+1;
		}
	}

	cout << minMoonies << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}
