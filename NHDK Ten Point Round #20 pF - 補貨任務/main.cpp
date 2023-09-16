#include <bits/stdc++.h>
#define ll long long

using namespace std;

vector < pair <ll, ll> > item;
ll day[200005];

bool cmp(pair <ll, ll> p1, pair <ll, ll> p2)
{
    return p1.second>p2.second;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    ll i,j,a,b;
    cin >> n;
    for (i=1;i<=n;i++) {
        cin >> a >> b;
        item.push_back({a, b});
    }
    sort(item.begin(), item.end(), cmp);

    fill(day, day+200005, 0);

    ll ans=0;
    for (i=0;i<n;i++) {
        for (j=item[i].first;j>=1;j--) {
            if (day[j]==0) {
                day[j]=item[i].second;
                ans+=item[i].second;
                break;
            }
        }
    }


    cout << ans << "\n";
    return 0;
}
