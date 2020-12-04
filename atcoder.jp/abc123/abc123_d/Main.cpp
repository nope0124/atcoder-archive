#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<ll,vector<ll>> Data;
#define rep(i,n) for(ll i=0;i<(n);i++)
#define ALL(a) a.begin(),a.end()
int main(){
  vector<ll> n(3);
  rep(i,3) cin>>n[i];
  ll k;cin>>k;
  vector<vector<ll>> v(3);
  rep(i,3){
    rep(j,n[i]){
      ll tmp;cin>>tmp;
      v[i].push_back(tmp);
    }
    sort(ALL(v[i]),greater<ll>());
  }
  priority_queue<Data> que;
  que.push(Data(v[0][0]+v[1][0]+v[2][0],vector<ll>({0,0,0})));
  set<Data> st;
  rep(i,k){
    auto c=que.top();que.pop();
    cout<<c.first<<endl;
    rep(iter,3){
      if(c.second[iter]+1<n[iter]){
        ll sum=c.first-v[iter][c.second[iter]]+v[iter][c.second[iter]+1];
        auto num=c.second;num[iter]++;
        auto d=Data(sum,num);
        if(!st.count(d)) st.insert(d),que.push(d);
      }
    }
  }
}