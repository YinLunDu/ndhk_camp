#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n,k,i,j,tmp;
    ll pre[5002];
    cin >> n >> k;
    pre[0]=0;
    for (i=1;i<=n;i++) {
        cin >> tmp;
        pre[i]=pre[i-1]+tmp;
    }

    ll ans=0;
    for (i=1;i<=n;i++) {
        for (j=i;j<=n;j++) {
            if (pre[j]-pre[i-1]<=k)
                ans++;
        }
    }
    cout << ans << "\n";
    return 0;
}
