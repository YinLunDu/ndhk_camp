#include <bits/stdc++.h>
#define ll long long
using namespace std;

vector <ll> vec;
ll ans;

void my_merge (ll L, ll R)
{
    if (L==R) return;
    ll mid=(L+R)/2;
    my_merge(L, mid);
    my_merge(mid+1, R);

    vector <ll> sorted;
    sorted.clear();
    ll Lptr=L, Rptr=mid+1;

    ll cnt=0;
    ll L_remained=mid-L+1;

    while (Lptr<=mid && Rptr<=R) {
        if (vec[Lptr]<=vec[Rptr]) {
            sorted.push_back(vec[Lptr]);
            Lptr++;
            L_remained--;
        } else {
            sorted.push_back(vec[Rptr]);
            Rptr++;
            cnt+=L_remained;
        }
    }

    ans+=cnt;

    while (Lptr<=mid) {
        sorted.push_back(vec[Lptr]);
        Lptr++;
    }
    while (Rptr<=R) {
        sorted.push_back(vec[Rptr]);
        Rptr++;
    }
    ll i,j;
    for (i=L, j=0 ; i<=R ; i++, j++)
        vec[i]=sorted[j];
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n,tmp,times=1;
    while (cin >> n) {
        if (n==0) break;
        vec.clear();
        for (ll i=1;i<=n;i++) {
            cin >> tmp;
            vec.push_back(tmp);
        }
        ans=0;
        my_merge(0, n-1);
        cout << "Case #" << times << ": " << ans << "\n";
        times++;
    }
    return 0;
}
