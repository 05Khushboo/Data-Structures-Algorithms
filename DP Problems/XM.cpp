/*input
1
3 2
3 1 2
1 3
2 3
*/
// https://www.codechef.com/problems/XM
#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{   
    int N = 1E5 + 2;
    int dp[N][31][2], zeroes[N][31], ones[N][31], arr[N];
    int i, j, n, q, l, r, total, range, mx, t;
    ll cnt, ans;

    scanf("%d", &t);
    while(t--)
    {
        scanf("%d %d", &n, &q);

        for(i = 0; i <= (n+1); i++)
        {
            if(i >= 1 && i <= n) 
                scanf("%d", &arr[i]);

            for(j = 0; j < 31; j++)
            {
                zeroes[i][j] = ones[i][j] = 0;
                dp[i][j][0] = dp[i][j][1] = 0;
                
                if(i >= 1 && i <= n)
                {
                    if(arr[i] & (1 << j)) ones[i][j] = 1;
                    else zeroes[i][j] = 1;

                    ones[i][j] += ones[i-1][j];
                    zeroes[i][j] += zeroes[i-1][j];
                }
            }
        }

        for(i = n; i >= 1; i--)
        {
            for(j = 0; j < 31; j++)
            {
                r = i + (1 << j) - 1;
                if(r >= n)
                { 
                    dp[i][j][0] = zeroes[n][j] - zeroes[i-1][j];
                    dp[i][j][1] = ones[n][j] - ones[i-1][j];
                }
                else
                {
                    dp[i][j][0] = (zeroes[r][j] - zeroes[i-1][j]) + dp[r+1][j][1];
                    dp[i][j][1] = (ones[r][j] - ones[i-1][j]) + dp[r+1][j][0];
                }
            }
        }

        while(q--)
        {
            scanf("%d %d", &l, &r);
            ans = 0;
            for(j = 0; j < 31; j++)
            {
                total = r - l  + 1;
                mx = 1 << j;
                total /= mx;
                range = l + total * mx;
                cnt = 0;
                if(range > l)
                {
                    if(total & 1) cnt += dp[l][j][1] - dp[range][j][0];
                    else cnt += dp[l][j][1] - dp[range][j][1];
                }
                if(range <= r)
                {
                    if(total & 1) cnt += zeroes[r][j] - zeroes[range-1][j];
                    else cnt += ones[r][j] - ones[range-1][j];
                }
                
                ans += (cnt * mx);    
            }

            printf("%lld\n", ans);
        }

    }

    return 0;
}