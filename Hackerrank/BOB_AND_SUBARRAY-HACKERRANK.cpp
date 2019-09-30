// Approach
// Below steps for every ith bit, i = 31 to 0
// Iterate over the array and find all l length segments having ith bit 0
// From a l length segment fi = (l*(l+1))/2 subarrays are possible all having ith bit as 0
// Subarrays in which all elements have ith bit as 0 = sum all all possible subarrays discussed above
// If one or more elements in a subarray has ith bit = 1, then it will contribute to the sum a value of 1 << i (pow(2, i))
// Total subarrays = (n*(n+1))/2
// Subarrays having atleast one element with ith bit as 1, (count of req subarrays)
// count_req_subarrays = total_subarrays - subarrays having all elements with ith bit as 0
// count_req_subarrays will contribute a value of count_req_subarrays * (1 << i)

#include <bits/stdc++.h>
using namespace std;


int bitWiseOrSum(vector<int> &a, int n) {
    if(n == 0)
        return 0;
    int sum = 0;
    for(int i = 31; i >= 0; i--) {
        int mask = 1 << i;
        // number of subarrays having ith bit as 0
        int zeroSubarrays = 0;
        int l = 0;
        for(int i = 0; i < n; i++) {
            if(a[i] & mask) {
                // number of subarrays possible with l length segment in which all elements have ith bit as 0
                zeroSubarrays += (l * (l + 1))/2;
                l = 0;
            }
            else l++;
        }

        if(l > 0) {
            zeroSubarrays += (l * (l + 1))/2;            
        }

        sum += (((n * (n + 1)) / 2) - zeroSubarrays) * (1 << i);
    }
    return sum;
}

int main() {
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i = 0; i < n ; i++)
        cin>>a[i];

    cout<<bitWiseOrSum(a, n)<<endl;

}
