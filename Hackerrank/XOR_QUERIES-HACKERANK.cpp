// Suyash Deshpande

#include <bits/stdc++.h>
using namespace std;

bool overlaps(int l1, int r1, int l2, int r2) {
    if(r1 > r2) {
        swap(l1, l2);
        swap(r1, r2);
    }
    if(l2 > r1) return false;
    return true;
}

int solve(int x, int l, int r) {
    int y = 0;
    int ans = 0;
    for(int i = 30; i >= 0; i--) {
        // if i bit in x is 0
        if(!(x & (1 << i))) {
            int temp = y | (1 << i);
            if(temp <= r) {
                ans += 1 << i;
                y = y | (1 << i);
            }
        }
        
        else {
            if(overlaps(y, y + (1 << i) - 1, l, r)) {
                ans += 1 << i;
            }
            else {
                y = y | (1 << i);
            }
        }
        
        
    }

    
    return ans;

}


int main() {
    int q;
    cin >> q;
    while(q--) {
        int x, l, r;
        cin >> x >> l >> r;
        cout<<solve(x, l, r) << endl;
    }
}
