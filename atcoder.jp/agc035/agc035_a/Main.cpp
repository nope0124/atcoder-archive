#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define rep(i, n) for(ll i = 0; i < (n); i++)

int main(){
    ll N,ans = 0;
    cin >> N;
    vector<ll> A(N);
    rep(i,N){
        cin >> A[i];
        ans ^= A[i];
    }

    if (ans == 0) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}

