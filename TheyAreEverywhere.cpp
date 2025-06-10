#include <bits/stdc++.h>
using namespace std;
set<char> types;
int n;
vector<int> pokemons;
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++) {
        char a;
        cin >> a;
        pokemons.push_back(a);
        types.insert(a);
    }
    
    int bestdist = 100001;
    int left = 0;
    int right = 0;
    unordered_map<char, int> pokemon;
    for (int right = 0; right < n; right++) {
        pokemon[pokemons[right]] += 1;
        while (left < right && pokemon.count(pokemons[left]) && pokemon.count(pokemons[left]) > 1) {
            pokemon[pokemons[left]]--;
            left++;
        }
        
        if (pokemon.size() == types.size()) {
            bestdist = min(bestdist, right-left+1);
        }
    }
    
    cout << bestdist;
    return 0;
}