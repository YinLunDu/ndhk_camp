#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    int n,u,d,l,r;
    int r_u,r_d,r_l,r_r;
    int a,b,c,e;

    while (t--) {
        cin >> n >> u >> r >> d >> l;

        bool fail=false;
        for (a=0;a<=1;a++) {
            for (b=0;b<=1;b++) {
                for (c=0;c<=1;c++) {
                    for (e=0;e<=1;e++) {
                        r_u=0,r_d=0,r_l=0,r_r=0;
                        if (a==1) {r_l++; r_u++;}
                        if (b==1) {r_u++; r_r++;}
                        if (c==1) {r_r++; r_d++;}
                        if (e==1) {r_d++; r_l++;}

                        fail=false;
                        if (!(0<=u-r_u && u-r_u<=n-2)) fail=1;
                        if (!(0<=d-r_d && d-r_d<=n-2)) fail=1;
                        if (!(0<=r-r_r && r-r_r<=n-2)) fail=1;
                        if (!(0<=l-r_l && l-r_l<=n-2)) fail=1;

                        if (!fail) break;
                    }
                    if (!fail) break;
                }
                if (!fail) break;
            }
            if (!fail) break;
        }
        if (!fail)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}
