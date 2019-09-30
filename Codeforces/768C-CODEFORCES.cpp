// Suyash Deshpande

#include <bits/stdc++.h>
using namespace std;

int main() {
    
    int n, k, x;
    cin>>n>>k>>x;
    vector<int>freq(1500, 0);

    for(int i = 0; i < n; i++) {
        int a;
        cin>>a;
        freq[a]++;
    }

    vector<int>temp(1500, 0);
    while(k--) {
        temp = freq;
        int parity = 0;
        for(int i = 0; i < 1500; i++) {
            if(freq[i] > 0) {
                int curr = i ^ x;
                int changeValue = freq[i] / 2;
                if(!parity) {
                    // consider ceil
                    changeValue += (freq[i] & 1);
                }
                temp[i] -= changeValue;
                temp[curr] += changeValue;
                parity ^= (freq[i] & 1);
            }
        }
        freq = temp;
    }
    int minValue = INT_MAX, maxValue = INT_MIN;
    for(int i = 0; i  < 1500; i++) {
        if(freq[i] > 0) {
            minValue = min(minValue, i);
            maxValue = max(maxValue, i);
        }
    }
    cout<<maxValue<<" "<<minValue<<endl;

}
