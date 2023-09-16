/**
 Â÷´²¤Æ + BIT
 **/
#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MAXN=2e5;

int bit[MAXN+5];
vector <int> vec, vec2;

int query(int idx)
{
    int mx=0;
    while (idx>0) {
        mx=max(mx, bit[idx]);
        idx-=(idx&-idx);
    }
    return mx;
}

void update(int idx, int val)
{
    while (idx<=MAXN) {
        bit[idx]=max(bit[idx], val);
        idx+=(idx&-idx);
    }
    return;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    fill(bit, bit+MAXN, 0);
    int n, i, tmp;
    cin >> n;
    for (i=1;i<=n;i++) {
        cin >> tmp;
        vec.push_back(tmp);
        vec2.push_back(tmp);
    }
    sort(vec2.begin(), vec2.end());
    vec2.resize( unique(vec2.begin(), vec2.end()) - vec2.begin());

    for (i=0;i<n;i++)
        vec[i]=lower_bound(vec2.begin(), vec2.end(), vec[i])
               -vec2.begin()+1;

    int ans=0;
    for (i=0;i<n;i++) {
        int tmp=vec[i];
        int cnt=query(tmp-1);
        cnt++;
        update(tmp, cnt);
        ans=max(ans, cnt);
    }
    cout << ans << "\n";

    return 0;
}
