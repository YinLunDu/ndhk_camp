#include <bits/stdc++.h>
#define ll long long

using namespace std;


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll q;
    cin >> q;
    cin.ignore();
    string s;
    while (q--) {
        getline(cin, s);
        stack <char> st;
        bool success=true;
        for (auto it:s) {
            if (it=='(' || it=='[')
                st.push(it);
            else {
                if (it==')') {
                    if (st.empty()) {
                        success=false;
                        break;
                    } else if (st.top()!='(') {
                        success=false;
                        break;
                    } else {
                        st.pop();
                    }
                }
                if (it==']') {
                    if (st.empty()) {
                        success=false;
                        break;
                    } else if (st.top()!='[') {
                        success=false;
                        break;
                    } else {
                        st.pop();
                    }
                }
            }
        }
        if (success && st.empty()) cout << "Yes\n";
        else cout << "No\n";
    }

    return 0;
}
