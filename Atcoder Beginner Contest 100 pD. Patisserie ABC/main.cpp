#include <bits/stdc++.h>
#define int long long

using namespace std;

int x[1005], y[1005], z[1005];

bool cmp(int a, int b) { return a>b; }

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    int i;
    for (i=1;i<=n;i++)
        cin >> x[i] >> y[i] >> z[i];

    int ans=-1e12;
    int a,b,c;
    for (a=0;a<=1;a++) {
        for (b=0;b<=1;b++) {
            for (c=0;c<=1;c++) {
                int arr[1005];
                for (i=1;i<=n;i++) {
                    arr[i]=0;
                    arr[i]+=(a==1 ? x[i] : -x[i]);
                    arr[i]+=(b==1 ? y[i] : -y[i]);
                    arr[i]+=(c==1 ? z[i] : -z[i]);
                }
                sort(arr+1, arr+n+1, cmp);
                int sum=0;
                for (i=1;i<=m;i++)
                    sum+=arr[i];
                ans=max(ans, sum);
            }
        }
    }
    cout << ans << "\n";
    return 0;
}
