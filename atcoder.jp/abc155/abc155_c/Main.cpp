//INCLUDE
//------------------------------------------
#include <bits/stdc++.h>
//DEFINE
//------------------------------------------
#define ll long long
#define ALLv(a)  (a).begin(),(a).end()
#define ALL(a,n)  (a),(a)+n
#define vi vector<long long>
#define vd vector<long double>
#define vs vector<string>
//CONST
//------------------------------------------
#define INF 1010000000000000017LL
#define MOD 1000000007LL
#define EPS 1e-12
#define PI 3.14159265358979323846
//REPEAT
//------------------------------------------
#define   FOR(i,m,n) for(ll (i)=(m);   (i)<(n);  (i)++)
#define   REP(i,n)   for(ll (i)=0;     (i)<(n);  (i)++)
#define  REPS(i,x)   for(ll (i)=1;     (i)<=(x); (i)++)
#define  RREP(i,x)   for(ll (i)=(x)-1; (i)>=0;   (i)--)
#define RREPS(i,x)   for(ll (i)=(x);   (i)> 0;   (i)--)
#define  WREP(i,in,j,jn) REP(i,in)REP(j,jn)
#define ifYN(x) cout<<(x?"APPROVED":"DENIED")<<"\n"
using namespace std;
//-------------------------------------------

int main(void){
  ll N;cin>>N;
  map<string,ll> mp;
  string s;
  REP(i,N){
    cin>>s;
    mp[s]++;
  }
  ll m=0;
  for(auto c:mp) m=max(m,c.second);
  //ll m=max_element(ALLv(mp))->second;
  //cout<<m<<endl;
  for(auto itr = mp.begin(); itr != mp.end(); ++itr) {
   if(m==itr->second)
    cout<<itr->first/*<<itr->second*/<<"\n";
  }
  return 0;
}
