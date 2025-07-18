#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> adj;
vector<bool> visited;  

double ans;

void dfs(int node, int current_length, double current_probability) {
	visited[node] = true;
	int possible_moves = 0;
  
	for (int x : adj[node]) {
		if (!visited[x]) { possible_moves++; }
	}

	if (!possible_moves) {
		ans += current_length * current_probability;
	} else {
    
		double new_probability = current_probability / possible_moves;
		for (int x : adj[node]) {
			if (!visited[x]) { dfs(x, current_length + 1, new_probability); }
		}
	}
}

int main() {
	cin >> n;
	adj.resize(n + 1);
	visited.resize(n + 1);

	for (int i = 1; i < n; i++) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	dfs(1, 0, 1);

	cout << setprecision(10) << ans << endl;
}
