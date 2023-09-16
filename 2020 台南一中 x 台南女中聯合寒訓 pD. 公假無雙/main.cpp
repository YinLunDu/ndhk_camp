#include <bits/stdc++.h>
#define ll long long

using namespace std;

int dp[1000005];

int main()
{
    ios::sync_with_stdio(0);
    int n,tmp;
    while (cin >> n) {
        int i;
        dp[0]=0;
        cin >> tmp;
        dp[1]=max(0,tmp);
        for (i=2;i<=n;i++) {
            cin >> tmp;
            dp[i]=max(dp[i-2]+tmp, dp[i-1]);
        }
        cout << dp[n] << "\n";
    }
    return 0;
}
