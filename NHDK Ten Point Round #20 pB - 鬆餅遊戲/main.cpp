#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n,m,tmp;
    ll i,j;
    ll ans[21][21]={0};
    cin >> n >> m;
    for (i=1;i<=n;i++) {
        for (j=1;j<=m;j++) {
            cin >> tmp;
            ans[i][j]=max(ans[i-1][j], ans[i][j-1])+tmp;
        }
    }
    cout << ans[n][m] << "\n";
    return 0;
}
