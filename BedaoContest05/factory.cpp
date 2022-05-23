#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int a[1000005];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k;
    cin >> n >> k;
    for(int i = 0; i<n; i++){
        cin >> a[i];
    }

    sort(a, a+n, greater<int>());

    if(k == 1){
        // output sum of all elements
        ll ans = 0;
        for(int i = 0; i<n; i++){
            ans += a[i];
        }
        cout << ans << endl;
    }else if(k == n){
        // output max of all elements
        cout << a[0] << endl;
    }else{
        int b[k];
        for(int i = 0; i<k; i++){
            b[i] = a[i];
        }

        for(int i = k; i<n; i++){
            int min_idx = 0;
            for(int j = 1; j<k; j++){
                if(b[j] < b[min_idx]){
                    min_idx = j;
                }
            }

            b[min_idx] += a[i];

            
        }

        int M = b[0];
        for(int j = 1; j<k; j++){
            if(b[j] > M){
                M = b[j];
            }
        }

        cout << M << endl;
    }

    return 0;
}
