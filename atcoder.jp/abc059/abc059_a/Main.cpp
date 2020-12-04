#include <bits/stdc++.h>
using namespace std;
int main(){
    string s_1,s_2,s_3;
    cin>>s_1>>s_2>>s_3;
    transform(s_1.begin(),s_1.end(),s_1.begin(),::toupper);
    transform(s_2.begin(),s_2.end(),s_2.begin(),::toupper);
    transform(s_3.begin(),s_3.end(),s_3.begin(),::toupper);
    cout<<s_1[0]<<s_2[0]<<s_3[0]<<endl;
}
