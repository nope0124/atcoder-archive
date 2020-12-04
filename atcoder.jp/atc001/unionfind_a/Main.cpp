#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define rep(i,n) for(ll i=0;i<(n);i++)
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
struct UnionFind{
    vector<ll> par;
    UnionFind(ll n) : par(n, -1) { }
    void init(ll n) { par.assign(n, -1); }
    
    ll root(ll x) {
        if (par[x] < 0) return x;
        else return par[x] = root(par[x]);
    }
    
    bool issame(ll x, ll y) {
        return root(x) == root(y);
    }
    
    bool merge(ll x, ll y) {
        x = root(x); y = root(y);
        if (x == y) return false;
        if (par[x] > par[y]) swap(x, y);
        par[x] += par[y];
        par[y] = x;
        return true;
    }
    
    ll size(ll x) {
        return -par[root(x)];
    }
};

int main(){
  IOS;
  ll n,q;cin>>n>>q;
  vector<ll> p(q),x(q),y(q);
  rep(i,q) cin>>p[i]>>x[i]>>y[i];
  UnionFind uf(n);
  rep(i,q){
    if(p[i]==0){
      uf.merge(x[i],y[i]);
    }else{
      if(uf.issame(x[i],y[i])) cout<<"Yes"<<endl;
      else cout<<"No"<<endl;
    }
  }
}