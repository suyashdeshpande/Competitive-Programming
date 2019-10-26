#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the timeConversion function below.
 */
string timeConversion(string s) {
   int b = s.length();
   if(s[b-2]=='A')
   {
       if(s[0]=='1' && s[1]=='2')
        {
           s[0]='0';s[1]='0';
       }
   }
    else{
        if(s[0]!='1' || s[1]!='2')    
        { s[0] = s[0]+1;
            s[1] = s[1]+2;
        }
    }
    return s.substr(0,8);
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = timeConversion(s);

    fout << result << "\n";

    fout.close();

    return 0;
}