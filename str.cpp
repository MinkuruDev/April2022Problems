#include <bits/stdc++.h>
using namespace std;

#define ll long long
const ll INF = 1000000000 + 7;

class Solution {
public:
    // longest substring without repeating characters
	int lengthOfLongestSubstring(string s) {
		int n = s.size();
		int ans = 0;
		int i = 0, j = 0;
		int m[255];
		for (int i = 0; i < 255; i++) m[i] = -1;
        while(i < n && j < n){
            if(m[s[j]] >= 0 ){
                i = max(i, m[s[j]] + 1);
            }
            m[s[j]] = j;
            j++;
            ans = max(ans, j-i);
        }
        
        return ans;
	}
};

// lcs function
int lcs(string s1, string s2){
    int n1 = s1.size();
    int n2 = s2.size();
    int dp[n1+1][n2+1];
    for(int i = 0; i <= n1; i++){
        for(int j = 0; j <= n2; j++){
            if(i == 0 || j == 0){
                dp[i][j] = 0;
            }
            else if(s1[i-1] == s2[j-1]){
                dp[i][j] = dp[i-1][j-1] + 1;
            }
            else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    return dp[n1][n2];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

	return 0;
}
