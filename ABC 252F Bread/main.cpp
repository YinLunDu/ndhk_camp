#include <bits/stdc++.h>
#define ll long long

using namespace std;

priority_queue <ll, vector<ll>, greater<ll>> pq;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n,l,tmp,i;
    cin >> n >> l;
    ll sum=0;
    for (i=1;i<=n;i++) {
        cin >> tmp;
        pq.push(tmp);
        sum+=tmp;
    }
    if (sum!=l)
        pq.push(l-sum);
    ll ans=0;
    while ((ll)pq.size()>1) {
        ll tmp1=pq.top();
        pq.pop();
        ll tmp2=pq.top();
        pq.pop();
        ans+=tmp1+tmp2;
        pq.push(tmp1+tmp2);
    }

    cout << ans << "\n";
    return 0;
}
