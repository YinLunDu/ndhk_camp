#include <bits/stdc++.h>
#define int long long
using namespace std;

int pre[2*1005];
int arr[1005];

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, p, i, j;
    cin >> n >> p;

    pre[0]=0;
    for (i=1;i<=n;i++) {
        cin >> arr[i];
        pre[i]+=pre[i-1]+arr[i];
    }
    int sum=pre[n];
    for (i=1;i<=n;i++)
        pre[n+i]+=pre[n+i-1]+arr[i];

    int loop=p/sum;
    int target=p%sum;

    int cnt=1e9; int ans1;

    for (i=1;i<=2*n;i++) {
        for (j=i;j<=2*n;j++) {
            int tmp=pre[j]-pre[i-1];
            if (tmp>=target) {
                if ((j-i+1)<cnt) {
                    cnt=j-i+1;
                    ans1=i;
                }
                break;
            }
        }
    }

    if (ans1>n) ans1-=n;

    if (p%sum==0)
        cout << ans1 << " " << loop*n << "\n";
    else
        cout << ans1 << " " << loop*n+cnt << "\n";
    return 0;
}
