#include<iostream>
#include<cstdio>
#include<cstring>
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 500005;
long long f[MAXN];
struct my_pair {
    int x;
    int s;
}pairs[MAXN];
long long  ok, lpos, rpos;
long long  n, d, k;
int path[MAXN];  // Add path array
bool check(int g)
{
    lpos = max(d - g, long long(1));//跳的最短距离 
    rpos = d + g;//跳的最长距离 
    memset(f, -127, sizeof(f));//设为很小的负数
    f[0] = 0;
    deque<int> dq;//定义一个双端队列 
    int cur = 0;//当前待入队的格子编号 
    for (int i = 1; i <= n; i++)
    {
        for (; cur < i && pairs[i].x - pairs[cur].x >= lpos; cur++)
        {
            if (dq.empty())
                dq.push_back(cur);
            else
            {
                while (!dq.empty() && f[cur] >= f[dq.back()])
                    dq.pop_back();
                dq.push_back(cur);
            }
        }
        while (!dq.empty() && pairs[i].x - pairs[dq.front()].x > rpos)
            dq.pop_front();
        if (!dq.empty())
        {
            f[i] = f[dq.front()] + pairs[i].s;
            path[i] = dq.front();
        }
        else
            f[i] = -999999999999;
        if (f[i] >= k)
            return 1;
    }

    return 0;
}

int main()
{
    int i, ans = -1, l, r, m;
    cin >> n >> d >> k;
    for (i = 1; i <= n; i++)
        cin >> pairs[i].x >> pairs[i].s;;
    //l = 0, r = 1005;//l表示投入的最少金币，r表示投入的最大金币
    l = 0, r = n > 1000 ? pairs[1000].x : pairs[n].x;
    m = (l + r) / 2;//m为上述区间的中间值，分治思想！！！！！
    while (l <= r)
    {
        //双指针的编程策略
        if (check(m))
        {
            ans = m;
            r = m - 1;
        }
        else
            l = m + 1;
        m = (l + r) / 2;
    }
    cout << ans<<endl;
    if (ans != -1) {
        vector<int> best_path;
        i = n;
        while (i > 0) {  // Trace back the path
            best_path.push_back(i);
            i = path[i];
        }
        reverse(best_path.begin(), best_path.end());  // Reverse the path
        for (int pos : best_path) {
            cout << pos << " ";
        }
        cout << endl;
    }
    return 0;
}