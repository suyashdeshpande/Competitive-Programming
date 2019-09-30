/// Suyash Deshpande

#include<bits/stdc++.h>
using namespace std;

const int size = 2001;
int dp[size][size];

int editDist(string str1, string str2){
    int m = str1.length();
    int n = str2.length();
    
    // dp[i][j] --> the minimum number of edits to transform str1[0...i-1] to str2[0...j-1]
    for(int i = 0; i <= m; i++){
        for(int j = 0; j <= n; j++){
            // If both strings are empty
            if(i == 0 && j == 0)
                dp[i][j] = 0;
            // If string a s empty, only option is to insert all characters of sting b
            else if(i == 0)
                dp[i][j] = j;
            // If string b is empty, only option is to delete all characters of string a
            else if(j == 0)
                dp[i][j] = i;
            // if last character is ame for both string, recur for the remaining
            else if(str1[i-1] == str2[j-1])
                dp[i][j] = dp[i-1][j-1];
            else
                dp[i][j] = 1 + min(min(
                                    dp[i-1][j],   //Remove 
                                    dp[i][j-1]),  //Insert
                                    dp[i-1][j-1]  //Replace
                                  );
        }
    }
    return dp[m][n];
}


int main() {
    int t;
    cin>>t;
    while(t--){
        string s1,s2;
        cin>>s1>>s2;
        cout<<editDist(s1,s2)<<endl;
    }
    return 0;
}
