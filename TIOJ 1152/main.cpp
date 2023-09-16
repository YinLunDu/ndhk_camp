#include <bits/stdc++.h>
#define ll long long

using namespace std;

vector <int> G[10005];
int dep[10005];
int ans=0;

int find_dep(int node)
{
    if (G[node].size()==0) {
        dep[node]=0;
        return 0;
    }
    int big=0, tmp;
    for (auto x:G[node]) {
        tmp=find_dep(x);
        if (tmp>big)
            big=tmp;
    }
    dep[node]=big+1;
    return big+1;
}

void DFS(int node)
{
    if (G[node].size()==0)
        return;
    else if (G[node].size()==1) {
        if (dep[node]>ans)
            ans=dep[node];
        return;
    } else {
        pair <int, int> big={0, 0};
        for (auto x:G[node]) {
            if (dep[x]>big.first)
                big={dep[x], big.first};
            else if (dep[x]>big.second)
                big={big.first, dep[x]};
        }
        if ((big.first+big.second+2)>ans)
            ans=big.first+big.second+2;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n, i, tmp;
    cin >> n;
    for (i=0;i<=n-1;i++) {
        while (cin >> tmp) {
            if (tmp==-1) break;
            G[i].push_back(tmp);
        }
    }
    find_dep(0);
    DFS(0);
    cout << ans << "\n";
    return 0;
}
