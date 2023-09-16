#include <bits/stdc++.h>
#define ll long long

using namespace std;

vector <ll> vec;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n,k,i,tmp,target;
    cin >> n >> k;
    for (i=1;i<=n;i++) {
        cin >> tmp;
        vec.push_back(tmp);
    }
    for (i=1;i<=k;i++) {
        cin >> target;
        int L=0, R=n-1;
        bool found=0;

        while (L<=R) {
            int mid=(L+R)/2;
            if (vec[mid]==target) {
                found=1;
                break;
            } else if (vec[mid]>target) {
                R=mid-1;
            } else {
                L=mid+1;
            }
        }
        if (found) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}
