#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using P = pair<ll, ll>;
using Graph = vector<vector<ll>>;
#define rep(i, n) for(ll i=0;i<(ll)(n);i++)
#define rep2(i, m, n) for(ll i=m;i<(ll)(n);i++)
#define rrep(i, n, m) for(ll i=n;i>=(ll)(m);i--)
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const int ddx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
const int ddy[8] = {1, 1, 0, -1, -1, -1, 0, 1};
const ll MOD = 1000000007;
const ll INF = 1000000000000000000L;
#ifdef __DEBUG

/**
 * For DEBUG
 * https://github.com/ta7uw/cpp-pyprint
 */
#include "cpp-pyprint/pyprint.h"

#endif

void Main() {
    
    string S; cin >> S;
    ll N=S.size();
    ll P=2019;
    ll ans = 0;

    // Pが10と互いに素かどうかで場合分け
    if (P == 2 || P == 5){ // 最下桁がPで割り切れればok
        rep(i, N){
            if ((S[i] - '0') % P == 0){
                ans += (i + 1);
            }
        }
    } else {
        // 10^{n} (modP)を事前に計算
        vector<ll> modp_table(N);
        modp_table.at(0) = 1;
        rep(i, N-1){
            modp_table.at(i + 1) = 10 * modp_table.at(i) % P;
        }

        // 右からn文字使った数のmodPの値で分類，modP = a が2つ以上あればその間を使って一つ作れる
        map<ll, ll> modp_cnt;
        rep(i, P){modp_cnt[i] = 0;}
        modp_cnt[0] = 1; // 累積和と同様，0文字使った時を初期化
        ll tmp = 0;
        rep(i, N){
            tmp += (S[N - 1 - i] - '0') * modp_table.at(i) % P;
            modp_cnt[tmp % P] += 1;
        }
        rep(i, P){
            ll n = modp_cnt[i];
            if (n >= 2){ans += n * (n - 1) / 2;}
        }
    }
    cout << ans << endl;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Main();
    return 0;
}
