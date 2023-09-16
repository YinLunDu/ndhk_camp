#include <bits/stdc++.h>
#define int long long

using namespace std;

pair<int, int> arr[10000];
int dp[1000][1000];

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,l,k;
    cin >> n >> l >> k;
    int i,j,p;
    for (i=1;i<=n;i++)
        cin >> arr[i].first;
    for (i=1;i<=n;i++)
        cin >> arr[i].second;
    sort(arr+1, arr+n+1);

    for (i=1;i<=n+1;i++)
        for (j=0;j<=k;j++)
            dp[i][j]=1e18;

    for (i=0;i<=k;i++)
        dp[1][i]=0;

    arr[n+1].first=l;

    for (i=2;i<=n+1;i++) {
        for (j=0;j<=k;j++) {
            for (p=i-1;p>=1;p--) {
                if (j-(i-p-1)<0) break;

                dp[i][j]=min(dp[i][j],
                             dp[p][j-(i-p-1)]+(arr[i].first-arr[p].first)*arr[p].second);
            }
        }
    }

    int ans=1e18;
    for (i=0;i<=k;i++)
        ans=min(ans, dp[n+1][i]);
    cout << ans << "\n";
    return 0;
}
