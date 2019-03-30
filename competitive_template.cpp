#include <bits/stdc++.h>
using namespace std;

#define SIEVE_SIZE 10000
#define ll long long
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define mod 1000000007
#define inf 999999999999999999

//prime sieve for a sieve size SIEVE_SIZE
vector<bool> sieve(SIEVE_SIZE, true);

// generate prime sieve from 2 to n
void buildSeive() {
    for (int i = 2; i * i <= SIEVE_SIZE; i++) {
        if (sieve[i] == true) {
            for (int j = i * i; j <= SIEVE_SIZE; j += i) {
                sieve[j] = false;
            }
        }
    }
}

int main() {



}
