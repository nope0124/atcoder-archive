#include <bits/stdc++.h>
using namespace std;
int main(){
    int a,b,c;
    cin >>a>>b>>c;
    vector<int> ans{a, b, c};
    sort(ans.begin(), ans.end());
    cout << ans[1] << endl;
}