#include <iostream>
using namespace std;

int cnt[10005];
int main()
{
    ios::sync_with_stdio(0);
    long long n;
    cin >> n;
    // cout << n;
    // bool flag = 1;
    for (int j = 1; j <= n; j++)
    {
        int j2 = j;
        for (int i = 2; 1ll * i * i <= j2; i++)
        {
            if (j2 % i == 0)
            {
                int tmp = 0;
                while (j2 % i == 0)
                {
                    j2 /= i;
                    tmp++;
                }
                cnt[i] += tmp;
            }
        }
        if (j2 > 1)
        {
            cnt[j2] += 1;
        }
    }
    // cout << endl;
    for(int i = 1;i<=n;i++) {
        if(cnt[i]) {
            cout << i << " "<<cnt[i]<<endl;
        }
    }
    return 0;
}