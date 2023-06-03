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
bool check(int g)
{
    lpos = max(d - g,long long(1));//������̾��� 
    rpos = d + g;//��������� 
    memset(f, -127, sizeof(f));//��Ϊ��С�ĸ���
    f[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = i - 1; j >= 0; j--)
        {
            if (pairs[i].x-pairs[j].x < lpos) continue;
            if (pairs[i].x - pairs[j].x > rpos) break;
            f[i] = max(f[i], f[j] + pairs[i].s);
            if (f[i] >= k)
                return 1;
        }
    }
    return 0;
}

int main()
{
    int i, ans = -1, l, r, m;
    cin >> n >> d >> k;
    for (i = 1; i <= n; i++)
        cin >> pairs[i].x >> pairs[i].s;;
    l = 0, r = 1005;//l��ʾͶ������ٽ�ң�r��ʾͶ��������
    m = (l + r) / 2;//mΪ����������м�ֵ������˼�룡��������
    while (l <= r)
    {
        //˫ָ��ı�̲���
        if (check(m))
        {
            ans = m;
            r = m - 1;
        }
        else
            l = m + 1;
        m = (l + r) / 2;
    }
    cout << ans;
    return 0;
}