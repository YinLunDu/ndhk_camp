#include <bits/stdc++.h>
#define int long long
using namespace std;

int arr[100005];
int pre[100005];

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,s;
    cin >> n >> s;
    int i;
    pre[0]=0;
    for (i=1;i<=n;i++) {
        cin >> arr[i];
        pre[i]=pre[i-1]+arr[i];
    }
    int cnt=0;
    int L, R;
    R=1;
    for (L=1;L<=n;L++) {
        if (arr[L]>s) continue;

        if (L>R) R=L;
        int tmp=pre[R]-pre[L-1];
        while (true) {
            if (R==n) break;
            if (tmp+arr[R+1]<=s) {
                tmp+=arr[R+1];
                R++;
            } else
                break;
        }
        cnt+=(1+(R-L+1))*(R-L+1)/2;
    }
    cout << cnt << "\n";
    return 0;
}
