#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,i,tmp;
    cin >> n;
    vector <int> vec;
    for (i=1;i<=n;i++) {
        cin >> tmp;
        vec.push_back(tmp);
    }
    int q, x;
    cin >> q;
    sort(vec.begin(), vec.end());
    while (q--) {
        cin >> x;
        cout << upper_bound(vec.begin(), vec.end(), x)-
                lower_bound(vec.begin(), vec.end(), x) << "\n";
    }
    return 0;
}
