#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int i;
    int arr[2005];
    for (i=1;i<=n;i++)
        cin >> arr[i];

    sort(arr+1, arr+n+1);
    int cnt=0;
    for (i=1;i<=n-2;i++) {
        int j=i+1, k=n;
        while (j<k) {
            if (i+j<=k)
                j++;
            else {
                k--;
                cnt++;
            }
        }
    }
    cout << cnt << "\n";
    return 0;
}
