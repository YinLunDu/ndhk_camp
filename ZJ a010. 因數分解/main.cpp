#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, num=1, i;
    cin >> n;
    for (i=2;i*i<=n;i++) {
        int cnt=0;
        if (n%i==0) {
            while (n%i==0) {
                n/=i;
                cnt++;
            }
            if (num==1) {
                if (cnt==1) cout << i;
                else cout << i << "^" << cnt;
            } else {
                if (cnt==1) cout << " * " << i;
                else cout << " * " << i << "^" << cnt;
            }
            num++;
        }
    }
    if (n!=1) {
        if (num==1) {
            cout << n;
        } else {
            cout << " * " << n;
        }
    }

    cout << "\n";
    return 0;
}
