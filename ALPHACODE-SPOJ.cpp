// Suyash Deshpande
#include<bits/stdc++.h>
using namespace std;


int main() {
    string a;
    int i,j;
    cin>>a;
    while(a[0]!='0') {
        int n = a.size();
        vector<long long int>b(n);

        // b[i] represents ways to decode array from index 0 to i
        for(i=0;i<n;i++)
            b[i]= 0;

        b[0]= 1;

        for(i=1;i<n;i++) {

            j= (a[i-1] - '0') * 10 + (a[i] - '0');
            if(a[i]- '0')
                b[i]= b[i-1];
             if(j>9 && j<27)  {
                 if(i==1)
                    b[i]= b[i] + 1;
                 else
                    b[i]= b[i] + b[i-2];
             }

        }
        cout<<b[n-1]<<endl;
        cin>>a;
    }
    if(a[0]=='0')
        return 0;
}
