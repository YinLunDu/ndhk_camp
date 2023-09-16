#include <bits/stdc++.h>
#define ll long long

using namespace std;

vector <pair<ll, ll>> input;
vector <ll> tmp;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n,i,x,y;
    cin >> n;
    for (i=1;i<=n;i++) {
        cin >> x >> y;
        input.push_back({x, y});
    }
    sort(input.begin(), input.end());
    for (auto it:input) {
        ll idx=upper_bound(tmp.begin(), tmp.end(), it.second)-tmp.begin();
        if (idx==tmp.size())
            tmp.push_back(it.second);
        else {
            tmp[idx]=it.second;
        }
    }
    cout << tmp.size() << "\n";
    return 0;
}
