#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

map<char, int> m;

void init(){
    m['I'] = 1;
    m['V'] = 5;
    m['X'] = 10;
    m['L'] = 50;
    m['C'] = 100;
    m['D'] = 500;
    m['M'] = 1000;
}

string convertToRoman(ll n){
    string ans = "";
    if(n >= 1000){
        ll q = n / 1000;
        ans += string(q, 'M');
        n %= 1000;
    }
    if(n >= 900){
        ans += "CM";
        n -= 900;
    }
    if(n >= 500){
        ans += "D";
        n -= 500;
    }
    if(n >= 400){
        ans += "CD";
        n -= 400;
    }
    if(n >= 100){
        ll q = n / 100;
        ans += string(q, 'C');
        n %= 100;
    }
    if(n >= 90){
        ans += "XC";
        n -= 90;
    }
    if(n >= 50){
        ans += "L";
        n -= 50;
    }
    if(n >= 40){
        ans += "XL";
        n -= 40;
    }
    if(n >= 10){
        ll q = n / 10;
        ans += string(q, 'X');
        n %= 10;
    }
    if(n >= 9){
        ans += "IX";
        n -= 9;
    }
    if(n >= 5){
        ans += "V";
        n -= 5;
    }
    if(n >= 4){
        ans += "IV";
        n -= 4;
    }
    if(n >= 1){
        ans += string(n, 'I');
    }
    return ans;
}

ll romanToInt(string roman){
    ll ans = 0;
    for(int i = 0; i < roman.size(); i++){
        if(i + 1 < roman.size() && m[roman[i]] < m[roman[i + 1]]){
            ans -= m[roman[i]];
        }
        else{
            ans += m[roman[i]];
        }
    }
    return ans;
}

int main(){
    init();
    ll n;
    cin >> n;
    cout << n << " = " << convertToRoman(n) << endl;
    return 0;
}