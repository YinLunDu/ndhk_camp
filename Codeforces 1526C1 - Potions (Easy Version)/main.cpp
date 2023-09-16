#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll arr[2005];
priority_queue <ll, vector<ll>, greater<ll>> pq;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n,i;
    cin >> n;
    for (i=1;i<=n;i++)
        cin >> arr[i];

    ll ans=0; ll now=0;
    for (i=1;i<=n;i++) {
        if (arr[i]>=0) {
            ans++;
            pq.push(arr[i]);
            now+=arr[i];
        } else {
            if (pq.size()==0) continue;

            if (now+arr[i]>=0) {
                ans++;
                pq.push(arr[i]);
                now+=arr[i];
            } else {
                ll tmp=pq.top();
                if (tmp<arr[i]) {
                    pq.pop();
                    pq.push(arr[i]);
                    now+=(arr[i]-tmp);
                }
            }
        }
    }
    cout << ans << "\n";
    return 0;
}
