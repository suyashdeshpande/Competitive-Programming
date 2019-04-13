#include <bits/stdc++.h>
using namespace std;

int t;

#define SIEVE_SIZE 10000
#define ll long long
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define mod 1000000007
#define inf 999999999999999999
#define test cin>>t; for(int testNum = 1;testNum<=t;testNum++)

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
    
// check if n is prime
bool isPrime(int n) { 
    // Corner cases 
    if (n <= 1)  return false; 
    if (n <= 3)  return true; 
  
    // This is checked so that we can skip  
    // middle five numbers in below loop 
    if (n%2 == 0 || n%3 == 0) return false; 
  
    for (int i=5; i*i<=n; i=i+6) 
        if (n%i == 0 || n%(i+2) == 0) 
           return false; 
  
    return true; 
} 

int main() {



}
