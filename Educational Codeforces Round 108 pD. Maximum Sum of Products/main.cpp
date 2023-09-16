#include <bits/stdc++.h>
#define int long long

using namespace std;

int a[5005], b[5005];
int pre[5005];

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,i;
    cin >> n;
    for (i=1;i<=n;i++)
        cin >> a[i];
    for (i=1;i<=n;i++)
        cin >> b[i];

    pre[0]=0;
    for (i=1;i<=n;i++)
        pre[i]=pre[i-1]+a[i]*b[i];

    int l,r;
    int mx=pre[n];

    for (i=1;i<=n;i++) {
        int sum=a[i]*b[i];
        for (l=i-1, r=i+1;l>=1 && r<=n;l--, r++) {
            sum+=a[l]*b[r];
            sum+=b[l]*a[r];
            mx=max(mx, sum+(pre[l-1]-0)+(pre[n]-pre[r]));
        }

        sum=0;
        for (l=i, r=i+1;l>=1 && r<=n;l--, r++) {
            sum+=a[l]*b[r];
            sum+=b[l]*a[r];
            mx=max(mx, sum+(pre[l-1]-0)+(pre[n]-pre[r]));
        }
    }
    cout << mx << "\n";

/**   Time:O(n^2)

    for (l=1;l<=n;l++) {
        for (r=l+1;r<=n;r++) {
            int sum=(pre[l-1]-0)+(pre[n]-pre[r]);
            int mid;
            if ((l+r)%2==0) {
                mid=(l+r)/2;
                sum+=a[mid]*b[mid];
            } else {
                mid=(l+r)/2+1;
            }

            for (i=l;i<mid;i++) {
                int idx=r-(i-l);
                sum+=a[i]*b[idx];
                sum+=b[i]*a[idx];
            }

            if (sum>mx)
                mx=sum;
        }
    }
    cout << mx << "\n";
**/

    return 0;
}
