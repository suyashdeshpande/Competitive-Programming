#include <bits/stdc++.h>
#define SIEVE_SIZE 10000
using namespace std;

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