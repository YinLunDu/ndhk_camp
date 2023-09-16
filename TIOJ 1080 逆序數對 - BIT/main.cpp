#include <bits/stdc++.h>
#define int long long

using namespace std;

vector <int> vec, vec2;
int bit[100005];

int query(int idx)
{
    int sum=0;
    while (idx>0) {
        sum+=bit[idx];
        idx-=(idx&-idx);
    }
    return sum;
}

void update(int idx, int val)
{
    while (idx<=100000) {
        bit[idx]+=val;
        idx+=(idx&-idx);
    }
    return;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    int times=1;
    while (true) {
        vec.clear();
        vec2.clear();
        cin >> n;
        if (n==0) break;

        int i;
        int tmp;
        for (i=0;i<n;i++) {
            cin >> tmp;
            vec.push_back(tmp);
            vec2.push_back(tmp);
        }
        sort(vec2.begin(), vec2.end());
        vec2.resize( unique(vec2.begin(), vec2.end()) - vec2.begin());
        for (i=0;i<n;i++)
            vec[i]=lower_bound(vec2.begin(), vec2.end(), vec[i])
                   -vec2.begin()+1;

        fill(bit, bit+100005, 0);
        int ans=0;
        for (i=n-1;i>=0;i--) {
            tmp=vec[i];
            int cnt=query(tmp-1);
            ans+=cnt;
            update(tmp, 1);
        }
        cout << "Case #" << times << ": " << ans << "\n";
        times++;
    }
    return 0;
}
