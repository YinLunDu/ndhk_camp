#include <bits/stdc++.h>
#define ll long long

using namespace std;

/// k -------> i
/// bi×(bi−2)−ak×(ak+5)

pair <ll, ll> stu[200005];

bool cmp(pair <ll, ll> p1, pair <ll, ll> p2)
{
    if (p2.second*(p2.second-2)-p1.first*(p1.first+5)<
        p1.second*(p1.second-2)-p2.first*(p2.first+5))
        return true;
    else
        return false;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n, i;
    cin >> n;
    for (i=0;i<n;i++)
        cin >> stu[i].first;
    for (i=0;i<n;i++)
        cin >> stu[i].second;
    sort(stu, stu+n, cmp);

    ll pre[200005];
    pre[0]=stu[0].first*(stu[0].first+5);
    for (i=1;i<n;i++)
        pre[i]=pre[i-1]+stu[i].first*(stu[i].first+5);

    ll ans=0;
    for (i=1;i<n;i++)
        ans+=i*stu[i].second*(stu[i].second-2)-pre[i-1];

    cout << ans << "\n";
    return 0;
}
