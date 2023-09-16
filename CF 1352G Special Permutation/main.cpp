#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int Q,n,i;
    deque <int> dq;
    cin >> Q;
    while (Q--) {
        cin >> n;
        if (n<=3) {
            cout << "-1\n";
            continue;
        }

        dq.clear();
        dq.push_back(3);
        dq.push_back(1);
        dq.push_back(4);
        dq.push_back(2);
        for (i=5;i<=n;i++) {
            if (i%2==1)
                dq.push_front(i);
            else
                dq.push_back(i);
        }
        for (auto it=dq.begin();it!=dq.end();it++)
            cout << *it << " ";
        cout << "\n";
    }
    return 0;
}
