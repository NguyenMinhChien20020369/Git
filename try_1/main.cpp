#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100000;

const unsigned long long MAGIC= 0xabcdef;
const long long MAGIC2 = 97;
const long long MOD = 1000000007;

char s[MAXN + 1];
unsigned long long h[MAXN + 1], pw[MAXN + 1];
long long h2[MAXN + 1], pw2[MAXN + 1];

pair<unsigned long long, long long> getHash(int i, int j)
{
    return make_pair(h[j + 1] - h[i] * pw[j - i + 1], (h2[j + 1] - h2[i] * pw2[j - i + 1] % MOD + MOD) % MOD);
}

int main()
{
    int n, m;
    assert(scanf("%d%d", &n, &m) == 2);
    assert(1 <= n && n <= MAXN);
    assert(1 <= m && m <= MAXN);
    assert(scanf("%s", s) == 1);
    assert(strlen(s) == n);

    pw[0] = pw2[0] = 1;
    h[0] = h2[0] = 0;
    for (int i = 0; i < n; ++i) {
        pw[i + 1] = pw[i] * MAGIC;
        pw2[i + 1] = pw2[i] * MAGIC2 % MOD;
        h[i + 1] = h[i] * MAGIC + s[i];
        h2[i + 1] = (h2[i] * MAGIC2 + (s[i] - 'a' + 1)) % MOD;
        assert('a' <= s[i] && s[i] <= 'z');
    }
    /*for (int i = 1; i <= n; ++i)
    {
        cout<<pw[i]<<" "<<pw2[i]<<" "<<h[i]<<" "<<h2[i]<<endl;
    }*/
    int SQRTN = (int)sqrt(n);
    vector< vector<int> > f(n, vector<int>(SQRTN + 1, 0));
    for (int i = n - 1; i >= 0; -- i) {
        for (int length = 1; length <= SQRTN; ++ length) {
            if (i + length <= n) {
                if (i + length * 2 <= n && getHash(i, i + length - 1) == getHash(i + length, i + length * 2 - 1)) {
                    f[i][length] = f[i + length][length] + 1;
                } else {
                    f[i][length] = 1;
                }
            } else {
                f[i][length] = 0;
            }
        }
    }

    long long total = 0;
    for (int i = 0; i < m; ++ i) {
        int a, b;
        assert(scanf("%d%d", &a, &b) == 2);
        assert(1 <= a && a <= b && b <= n);
        -- a; -- b;
        if (b - a + 1 <= SQRTN) {
            printf("%d\n", f[a][b - a + 1]);
            total += f[a][b - a + 1];
        } else {
            int answer = 1;
            int length = b - a + 1;
            int ptr = b + 1;
            pair<unsigned long long, long long> target = getHash(a, b);
            while (ptr + length <= n && getHash(ptr, ptr + length - 1) == target) {
                ptr += length;
                ++ answer;
            }
            printf("%d\n", answer);
            total += answer;
        }
    }
    //fprintf(stderr, "%I64d\n", total);
    return 0;
    */
}
