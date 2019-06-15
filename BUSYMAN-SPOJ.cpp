// Suyash Deshpande
#include <bits/stdc++.h>
using namespace std;

bool compare(pair<int, int>&a, pair<int, int>&b) {
    return a.second < b.second;
}

int main() {
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        vector<pair<int, int>>v(n);
        for(int i = 0; i < n; i++) {
            int n, m;
            cin>>m>>n;
            v[i] = {m, n};
        }
        sort(v.begin(), v.end(), compare);
        int count = 0;
        int prevEndTime = 0;
        for(int i = 0; i < n; i++) {
            if(v[i].first >= prevEndTime) {
                count++;
                prevEndTime = v[i].second;
            }
        }
        cout<<count<<endl;
    }
}
