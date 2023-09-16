/**
 先排序按按鈕
 前啜和
 對每筆提問二分搜
 **/
#include <bits/stdc++.h>

using namespace std;

vector <long> button;

int main()
{
    ios::sync_with_stdio(0);

    int n,m;

    while (cin >> n >> m) {
        button.clear();
        long tmp;
        int i;
        for (i=0;i<n;i++) {
            cin >> tmp;
            button.push_back(tmp);
        }
        sort(button.begin(),button.end());
        int p;

        for (i=1;i<=m;i++) {
            cin >> p;
            int index=upper_bound(button.begin(), button.end(), p)-button.begin();
            while (button[index]==p && index+1<n) index++;
            if (index%2==0)
                cout << "0\n";
            else
                cout << "1\n";
        }
    }
    return 0;
}
