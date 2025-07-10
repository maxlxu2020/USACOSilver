	#include <bits/stdc++.h>
using namespace std;

struct Event {
	int time;
	int cow_id;
	bool is_start;
};

bool operator<(const Event &a, const Event &b) { return a.time < b.time; }

int main() {

	int n;
	cin >> n;
	vector<Event> events;

	for (int i = 0; i < n; i++) {
		int l, r;
		cin >> l >> r;
		events.push_back({l, i, true});
		events.push_back({r, i, false});
	}

	sort(events.begin(), events.end());

	vector<int> alone_time(n);

	set<int> active;

	int prev_time = 0;

	int total_time = 0;

	for (const Event &e : events) {
		int curr_time = e.time;

		if (active.size() > 0) { total_time += curr_time - prev_time; }

		if (active.size() == 1) {
			alone_time[*active.begin()] += curr_time - prev_time;
		}

		if (e.is_start) {
			active.insert(e.cow_id);
		} else {
			active.erase(e.cow_id);
		}

		prev_time = curr_time;
	}

	int min_alone_time = *min_element(alone_time.begin(), alone_time.end());

	freopen("lifeguards.out", "w", stdout);
	cout << total_time - min_alone_time << endl;
}
