#include <bits/stdc++.h>
using namespace std;
int main() {
    int a;
    set<int> st;
    for (int i = 0; i < 3; i++) {
        cin >> a;
        st.insert(a);
    }
    cout << st.size() << endl;
}
