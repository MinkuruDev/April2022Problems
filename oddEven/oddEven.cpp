#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll playerMoney = 200000;
double rate = 2.45;

bool playOneGame(ll bet, char choice){
    if(choice == 'r'){
        if(rand()%100 < 50)
            return playOneGame(bet, 'o');
        else
            return playOneGame(bet, 'e');
    }

    int result = rand() % 10;
    playerMoney -= bet;

    if(result == 0 || result == 9)
        return false;

    result %= 2;
    if(choice == 'o'){
        if(result == 1){
            playerMoney += (ll)(bet * rate);
            return true;
        }
    }else{
        if(result == 0){
            playerMoney += (ll)(bet * rate);
            return true;
        }
    }

    return false;
}

void playOneRound(ll firstBet, char choice = 'r'){
    const ll maxBet = 21000;
    ll bet = firstBet;
    bool win = false;
    while(bet <= maxBet && !win){
        win = playOneGame(bet, choice);
        bet *= 2;
    }
}

int main(){
    srand(time(NULL));
    const int rounds = 20;
    // play round times and print the result after each round
    ll maxMoney = 0;
    ll minMoney = playerMoney;
    for(int i = 0; i < rounds; i++){
        playOneRound(1000);
        maxMoney = max(maxMoney, playerMoney);
        minMoney = min(minMoney, playerMoney);
        cout << "Player money after round " << i+1 << ": " << playerMoney << endl;
    }

    cout << "Max money: " << maxMoney << endl;
    cout << "Min money: " << minMoney << endl;

    return 0;
}