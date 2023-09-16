#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie();
    vector < pair <int, int> > vec;
    int n,i,a,b;
    cin >> n;
    for (i=1;i<=n;i++) {
        cin >> a >> b;
        vec.push_back(make_pair(a,b));
    }
    sort(vec.begin(), vec.end());
    for (i=0;i<n;i++) {
        cout << vec[i].first << " " << vec[i].second << "\n";
    }
    return 0;
}
