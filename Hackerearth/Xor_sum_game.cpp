#include <bits/stdc++.h>
using namespace std;
map<int,long long> powers;
long long utilPower(int i)
{
    long long prod = 1;
    for(int j=0;j<i;j++)
    {
        prod = prod*2;
    }
    return prod;
}
long long solve (long long A) 
{  
    long long num = 0,tmp=0;
    int bit;
    int count = 0;
    while(A>=0)
    {
        bit = A%2;
        if(bit==0)
        {
            num = powers[count];
            break;
        }
        A = A/2;
        count++;
    }
    return num;
}
 
int main() 
{
    
    int i_S;
    int T = 0;
    long long A = 0;
    
    cin>>T;
    for(int i=0;i<=60;i++)
    {
        powers[i] = utilPower(i);
    }
    for(i_S=0; i_S<T; i_S++) {
        cin>>A;
        long long out_ = solve(A);
        cout<<out_<<endl;
    }
}