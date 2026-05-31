// https://open.kattis.com/problems/qanat

#include <bits/stdc++.h>
#define ld long double
#define pdd pair<ld, ld>
#define vpdd vector<pdd>
using namespace std;

ld costo(ld a, ld x)
{
    ld vh = x * a;
    ld len = vh + a + (1.0L - x);

    return (len * len) / 4.0L - (vh * vh) / 2.0L;
};

int main()
{
    ld w, h, a;
    int n;
    cin >> w >> h >> n;

    a = h / w;

    vpdd dp(n + 1);

    dp[0] = pdd(0.0L, ((a + 1.0L) / 2.0L) * ((a + 1.0L) / 2.0L));

    for (int i = 1; i <= n; i++)
    {
        ld inf = 0.0L, sup = 1.0L;

        for (int it = 0; it < 100; it++)
        {
            ld m1 = inf + (sup - inf) / 3.0L;
            ld m2 = sup - (sup - inf) / 3.0L;

            ld c1 = costo(a, m1) + dp[i - 1].second * m1 * m1;
            ld c2 = costo(a, m2) + dp[i - 1].second * m2 * m2;

            if (c1 < c2)
                sup = m2;
            else
                inf = m1;
        }

        ld x = (inf + sup) / 2.0L;

        dp[i] = pdd(x, costo(a, x) + dp[i - 1].second * x * x);
    }

    cout << fixed << setprecision(10) << dp[n].second * w * w << endl;

    vector<ld> pos(n);
    ld mult = w;

    for (int i = n; i >= 1; i--)
    {
        mult *= dp[i].first;
        pos[i - 1] = mult;
    }

    for (int i = 0; i < min(n, 10); i++)
        cout << pos[i] << endl;

    return 0;
}