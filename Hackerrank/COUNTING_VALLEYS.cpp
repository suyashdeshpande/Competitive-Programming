#include <bits/stdc++.h>

using namespace std;

// Complete the countingValleys function below.
int countingValleys(int n, string s) {
    long alt{},palt{},vc{};
    for(int i=0;i<s.length();i++) {
        palt=alt;
        if(s[i]=='U')
        alt++;
        else
        alt--;
        if( alt==0 && palt<0)
        vc++;
    }
    return vc;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string s;
    getline(cin, s);

    int result = countingValleys(n, s);

    fout << result << "\n";

    fout.close();

    return 0;
}