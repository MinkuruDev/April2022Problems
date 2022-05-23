#include <bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if (n == 0) return "";
        int max_len = 1;
        int start = 0;
        for (int i = 0; i < n; i++) {
            int len1 = expandAroundCenter(s, i, i);
            int len2 = expandAroundCenter(s, i, i + 1);
            int len = max(len1, len2);
            if (len > max_len) {
                max_len = len;
                start = i - (len - 1) / 2;
            }
        }
        return s.substr(start, max_len);
    }

    int expandAroundCenter(string s, int left, int right) {
        int n = s.size();
        while (left >= 0 && right < n && s[left] == s[right]) {
            left--;
            right++;
        }
        return right - left - 1;
    }

    char guess(string pass, ll pos){
        ll n = pass.size();
        const ll N = n;
        while(n < pos){
            n *= 2;
        }
        pos--;
        while(n > N){
            n /= 2;
            if(pos < n)
                continue;
            pos += n-1;
            pos %= n;
            if(pos < N){
                return pass[pos];
            }
        }

        return pass[pos];
    }

    string longestDupSubstring(string s) {
        int s1l, s1r, s2l, s2r, r1l, r1r, r2l, r2r;
        s1l = s1r = s2l = s2r = r1l = r2l = r2r = -1;
        r1r = -2;
        map<char, vector<int>> mcv;
        int n = s.size();
        for(int i = 0; i < n; i++){
            mcv[s[i]].push_back(i);
        }

        bool noDupe = true;
        for(auto& pcv: mcv){
            if(pcv.second.size() == 1){
                continue;
            }
            noDupe = false;
            break;
        }
        if(noDupe) return "";

        for(int i = 0; i<n; i++){
            if(n-i < r1r - r1l) break;
            if((i >= r1l && i <= r1r) || (i >= r2l && i <= r2r))
                continue;
            s1l = s1r = i;
            vector<int> &v = mcv[s[i]];
            int j = upper_bound(v.begin(), v.end(), i) - v.begin();
            
            while(j < v.size()){
                s2l = s2r = v[j];
                if(n - s2r < r1r - r1l) break;
                s1r = s1l;
                int _j = j;
                j++;
                while (++_j < n){
                    //if(s2r+1 >= n) break;
                    if(s[++s1r] != s[++s2r]){
                        --s1r;
                        --s2r;
                        break;
                    }
                }

                if(s1r - s1l > r1r - r1l){
                    r1l = s1l;
                    r1r = s1r;
                    r2l = s2l;
                    r2r = s2r;
                }
            }
        }

        return s.substr(r1l, r1r - r1l + 1);
    }

    int binary_search(vector<int>& nums, int target){
        int n = nums.size();
        int left = 0, right = n-1;
        while(left <= right){
            int mid = left + (right-left)/2;
            if(nums[mid] == target)
                return mid;
            else if(nums[mid] < target)
                left = mid+1;
            else
                right = mid-1;
        }
        return -1;
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        int dp[202][202];
        const int INF = INT_MAX;
        memset(dp, INF, sizeof(dp));
        dp[1][1] = triangle[0][0];
        int n = triangle.size();
        for(int i = 1; i < n; i++){
            for(int j = 0; j <= i; j++){
                //dp[i+1][j] = min(dp[i][j-1], dp[i][j]) + triangle[i][j];
                dp[i+1][j+1] = min(dp[i][j], dp[i][j+1]) + triangle[i][j];
            }
        }

        int ans = INF;
        for(int i = 1; i <= n; i++){
            ans = min(ans, dp[n][i]);
        }

        return ans;
    }

    int nthSuperUglyNumber(int nth, vector<int>& primes) {
        // unsolved
        if(nth == 1) return 1;
        const int INF = INT_MAX;
        int n = primes.size();
        set<int> s;
        s.insert(1);
        primes.push_back(1);
        for(int i = 0; i<n; i++){
            long long p = primes[i];
            s.insert(p);
            while (p < INF){
                primes.push_back(p);
                p *= primes[i];
            }
        }

        n = primes.size();
        for(int i = 0; i<n; i++){
            for(int j = i+1; j<n; j++){
                long long p = 1ll*primes[i]*primes[j];
                if(p < INF){
                    s.insert(p);
                }
            }
        }

        set<int>::iterator it = s.begin();
        while(nth--){
            cout << *it << " ";
            it++;
        }
        return *it;
    }

    static const int N = 1005;
    vector<int> graph[N], group[N];
    bool visited[N] = {false};

    void dfs(int u, int g){
        visited[u] = true;
        group[g].push_back(u);
        for(int v: graph[u]){
            if(!visited[v]){
                dfs(v, g);
            }
        }
    }

    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n = s.size();
        for(auto& p: pairs){
            graph[p[0]].push_back(p[1]);
            graph[p[1]].push_back(p[0]);
        }

        int g = 0;
        for(int i = 0; i<n; i++){
            if(!visited[i]){
                dfs(i, g++);
            }
        }

        string ans = s;
        for(int i = 0; i<g; i++){
            string str = "";
            for(int u: group[i]){
                str += s[u];
            }
            sort(str.begin(), str.end());
            sort(group[i].begin(), group[i].end());
            cout << str << endl;
            int g_size = group[i].size();
            for(int j = 0; j<g_size; j++){
                ans[group[i][j]] = str[j];
            }
        }

        return ans;
    }

};

int main() {
    Solution s;
    string str = "dcab";
    vector<vector<int>> pairs = {{0,3},{1,2},{0,2}};
    cout << s.smallestStringWithSwaps(str, pairs) << endl;
    
    return 0;
}
