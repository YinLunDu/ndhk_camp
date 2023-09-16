#include <bits/stdc++.h>
#define int long long
using namespace std;

int prew[100005];
int w[100005];
int prec[100005];
int c[100005];

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, s, i;
    cin >> n >> s;
    prew[0]=0;
    for (i=1;i<=n;i++) {
        cin >> w[i];
        prew[i]=prew[i-1]+w[i];
    }
    prec[0]=0;
    for (i=1;i<=n;i++) {
        cin >> c[i];
        prec[i]=prec[i-1]+c[i];
    }

    int mx=0;
    int L, R=1;
    for (L=1;L<=n;L++) {
        if (L>R) R=L;

        int tmp=prew[R]-prew[L-1];
        if (tmp>s) continue;

        while (true) {
            if (R==n) break;
            if (tmp+w[R+1]<=s) {
                tmp+=w[R+1];
                R++;
            } else {
                break;
            }
        }
        mx=max(mx, prec[R]-prec[L-1]);
    }
    cout << mx << "\n";
    return 0;
}
