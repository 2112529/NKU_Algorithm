// robot_game.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 500010;
int n, d, k;
int g=0;

struct my_pair {
    int x;
    int s;
};
long long score;


int main()
{
    cin >> n >> d >> k;
    vector<my_pair> pairs(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> pairs[i].x >> pairs[i].s;

    // 将所有格子按分数从大到小排序
    sort(pairs.begin() + 1, pairs.end(), [](my_pair a, my_pair b) {
        return a.s > b.s;
        });

    //1.选择贪心算法进行求解，实现局部最优
    //每一次都选择范围内最优的进行求解
    int lastPos = 0;
    while (score < k)
    {
        g++;
        bool found = false;
        for (int i = 1; i <= n; i++)
        {
            // 计算格子i与上一次跳跃位置之间的距离
            int distance = abs(pairs[i].x - lastPos);
            // 如果在当前跳跃范围内，就选择这个格子
            if (pairs[i].x>lastPos && distance >= max(d - g, 1) && distance <= d + g)
            {
                score += pairs[i].s;
                lastPos = pairs[i].x;
                found = true;
                break;
            }
        }
        // 如果在当前跳跃范围内找不到格子，就结束循环
        if (!found)
            break;
    }
    // 如果达到了目标分数，输出金币数量，否则输出-1
    if (score >= k)
        cout << g << endl;
    else
        cout << "-1" << endl;
    return 0;
    //2.采用dfs进行深度优先搜索尝试求解
     
     
    //3.选择动态规划进行求解

    
    
    //return 0;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
