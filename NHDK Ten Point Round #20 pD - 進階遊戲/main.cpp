#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll m,tmp;
    ll i,j;
    ll ans[4][5002]={0};
    cin >> m;
    for (i=1;i<=3;i++) {
        for (j=1;j<=m;j++) {
            cin >> tmp;
            ans[i][j]=max(ans[i-1][j], ans[i][j-1])+tmp;
        }
    }
    cout << ans[3][m] << "\n";
    return 0;
}
