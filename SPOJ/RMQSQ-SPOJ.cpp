// Suyash Deshpande
#include <bits/stdc++.h>
using namespace std;

vector<int>tree;

void buildTree(vector<int>a, int s, int e, int index) {

    if(s==e) {
        tree[index] = a[s];
        return;
    }
    int mid = (s+e)/2;
    buildTree(a, s, mid, 2*index);
    buildTree(a, mid+1, e, 2*index + 1);
    tree[index] = min(tree[2*index], tree[2*index + 1]);

}

int query(int ss, int se, int qs, int qe, int index) {
    //complete overlap
    if(ss>=qs && se<=qe) {
        return tree[index];
    }

    // no overlap
    if(ss>qe || se<qs) {
        return INT_MAX;
    }

    // partial overlap
    int mid = (ss+se)/2;
    int leftAns = query(ss, mid, qs, qe, 2*index);
    int rightAns = query(mid+1, se, qs, qe, 2*index + 1);
    return min(leftAns, rightAns);

}

int main() {
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++)
        cin>>a[i];
    tree.assign(4*n + 1, INT_MAX);
    buildTree(a, 0, n-1, 1);
    int q;
    cin>>q;
    while(q--) {
        int l,e;
        cin>>l>>e;
        cout<<query(0, n-1, l, e, 1)<<endl;
    }
}
