#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll dp[405][405];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    ll i,j,l,r;
    ll arr[405], pre[405];

    cin >> n;

    ll tmp=1e18;
    for (i=1;i<=n;i++)
        for (j=1;j<=n;j++)
            dp[i][j]=tmp;

    pre[0]=0;
    for (i=1;i<=n;i++) {
        cin >> arr[i];
        pre[i]=pre[i-1]+arr[i];
    }
    for (i=1;i<=n;i++)
        dp[i][i]=0;
    for (l=n;l>=1;l--) {
        for (r=l;r<=n;r++) {
            for (i=l;i<=r;i++) {
                dp[l][r]=min(dp[l][r], dp[l][i]+dp[i+1][r]+(pre[r]-pre[l-1]));
            }
        }
    }

    cout << dp[1][n] << "\n";
    return 0;
}
