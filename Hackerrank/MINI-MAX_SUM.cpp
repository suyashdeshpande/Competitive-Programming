#include <bits/stdc++.h>

using namespace std;

void miniMaxSum(vector <int> arr) {
    sort(arr.begin(),arr.end());
    long sum1=0,sum2=0;
    for(int i=0;i<4;i++)
        sum1 += arr[i];
    for(int i=1;i<5;i++)
        sum2 += arr[i];
    cout<<sum1<<" "<<sum2;
}

int main() {
    vector<int> arr(5);
    for(int arr_i = 0; arr_i < 5; arr_i++){
       cin >> arr[arr_i];
    }
    miniMaxSum(arr);
    return 0;
}
