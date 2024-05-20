#include <iostream>
#include <queue>
using namespace std;
//int tree[100005][10];
long long w[100005];
int n, k;
struct node
{
    long long w;
    long long len;
    bool operator<(const node &a) const
    {
        return w > a.w;
    }
};
priority_queue<node> q;

int main()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        long long tmp;
        cin >> tmp;
        q.push({tmp, 0});
    }
    while (k > 2 && n % (k - 1) != 1) {
        n ++;
        q.push({0,0});
    }
    long long ans = 0, ans2 = 0;
    while (!q.empty() && q.size() > 1)
    {
        long long tmp = 0, len = 0, t2 = 0;
        for (int i = 1; i <= k && !q.empty(); i++)
        {
            tmp += q.top().w;
            t2++;
            ans2 = max(ans2, q.top().len + 1);
            len = max(len, q.top().len + 1);
            q.pop();
        }
        q.push({tmp, len});
        ans += tmp;
    }
    cout << ans << endl << ans2;
    return 0;
}