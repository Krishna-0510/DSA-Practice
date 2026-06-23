class Solution {
public:
    static const int MOD = 1000000007;

    int zigZagArrays(int n, int l, int r) {
        int m = r - l + 1;

        vector<int> up(m + 1), down(m + 1);
        vector<int> newUp(m + 1), newDown(m + 1);
        vector<int> prefUp(m + 1), prefDown(m + 1);

        // length = 2
        for (int x = 1; x <= m; x++) {
            up[x] = x - 1;
            down[x] = m - x;
        }

        if (n == 2) {
            long long ans = 0;
            for (int x = 1; x <= m; x++) {
                ans = (ans + up[x] + down[x]) % MOD;
            }
            return (int)ans;
        }

        for (int len = 3; len <= n; len++) {

            prefUp[0] = 0;
            prefDown[0] = 0;

            for (int x = 1; x <= m; x++) {
                prefUp[x] = (prefUp[x - 1] + up[x]) % MOD;
                prefDown[x] = (prefDown[x - 1] + down[x]) % MOD;
            }

            for (int x = 1; x <= m; x++) {
                newUp[x] = prefDown[x - 1];

                newDown[x] = prefUp[m] - prefUp[x];
                if (newDown[x] < 0) {
                    newDown[x] += MOD;
                }
            }

            up.swap(newUp);
            down.swap(newDown);
        }

        long long ans = 0;

        for (int x = 1; x <= m; x++) {
            ans = (ans + up[x] + down[x]) % MOD;
        }

        return (int)ans;
    }
};