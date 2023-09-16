#include <bits/stdc++.h>

using namespace std;

vector <int> vec;

void mergesort(int L, int R)
{
    if (L == R) return;

    int mid=(L+R)/2;
    mergesort(L, mid);
    mergesort(mid+1, R);

    vector <int> sorted;
    int Lptr=L, Rptr=mid+1;
    while (Lptr<=mid && Rptr<=R) {
        if (vec[Lptr] < vec[Rptr]) {
            sorted.push_back(vec[Lptr]);
            Lptr++;
        } else {
            sorted.push_back(vec[Rptr]);
            Rptr++;
        }
    }
    while (Lptr<=mid) {
        sorted.push_back(vec[Lptr]);
        Lptr++;
    }
    while (Rptr<=R) {
        sorted.push_back(vec[Rptr]);
        Rptr++;
    }
    for (int i=0;i<=R-L;i++) {
        vec[L+i]=sorted[i];
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,i,tmp;

    while (cin >> n) {
        vec.clear();
        for (i=1;i<=n;i++) {
            cin >> tmp;
            vec.push_back(tmp);
        }
        mergesort(0, n-1);
        for (i=0;i<n;i++) {
            cout << vec[i] << " ";
        }
        cout << "\n";
    }

    return 0;
}
