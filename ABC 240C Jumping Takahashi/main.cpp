#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    //cin.tie(0);
    bitset <10005> now(0);
    int n,target;
    int i,x,y;
    cin >> n >> target;
    now[0]=1;

    bitset <10005> a,b;

    for (i=1;i<=n;i++) {
        cin >> x >> y;
        a = now << x;
        b = now << y;
        now = a | b;
        //cout << a << " " << b << "\n";
    }
    if(now[target]) cout << "Yes\n";
    else cout << "No\n";
    return 0;
}
