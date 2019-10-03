#include <bits/stdc++.h>
using namespace std;

bool ok(int x, int y, vector<pair<int, int>>&pairs) {
    for(auto p: pairs) {
        if(p.first != x && p.first != y && p.second != x && p.second != y)
            return false;
    }
    return true;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>>pairs;
    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        pairs.push_back({a, b});
    }

    for(int x: {pairs[0].first, pairs[0].second}) {
        if(ok(x, -1, pairs)) {
            cout << "YES" << endl;
            return 0;
        }
        else {
            for(int i = 1; i < m; i++) {
                if(pairs[i].first != x && pairs[i].second != x) {
                    if(ok(x, pairs[i].first, pairs) || ok(x, pairs[i].second, pairs)) {
                        cout << "YES" << endl;
                        return 0;                        
                    }
                    break;
                }
            }
        }
    }
    cout << "NO" << endl;

}
