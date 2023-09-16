#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long Q,x,a,b,n,i;
    bool success;
    cin >> Q;
    for (i=1;i<=Q;i++) {
        success=0;
        cin >> x;
        for (a=1;a*a*a<x;a++) {
            n=x-a*a*a;
            b=cbrt(n);
            if (b*b*b==n) {
                success=true;
                break;
            }
        }
        cout << (success ? "YES\n" : "NO\n");
    }
    return 0;
}
