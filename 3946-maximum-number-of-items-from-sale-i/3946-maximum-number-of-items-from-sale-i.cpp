
class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();
        vector<int> val(n);

        for (int i = 0; i < n; i++) {
            int cnt = 1;

            for (int j = 0; j < n; j++) {
                if (i != j && items[j][0] % items[i][0] == 0) {
                    cnt++;
                }
            }

            val[i] = cnt;
        }

        vector<int> order(n);
        iota(order.begin(), order.end(), 0);

        sort(order.begin(), order.end(), [&](int a, int b) {
            return items[a][1] > items[b][1];
        });

        const int NEG = -1e9;

        vector<int> dp(budget + 1, NEG);
        dp[0] = 0;

        int ans = 0;
        int k = 0;

        while (k < n) {
            int p = items[order[k]][1];
            vector<int> cur(budget + 1, NEG);

            while (k < n && items[order[k]][1] == p) {
                int id = order[k];
                int price = items[id][1];
                int value = val[id];

                for (int c = budget; c >= price; c--) {
                    if (dp[c - price] != NEG) {
                        cur[c] = max(cur[c], dp[c - price] + value);
                    }

                    if (cur[c - price] != NEG) {
                        cur[c] = max(cur[c], cur[c - price] + value);
                    }

                    if (dp[c - price] != NEG) {
                        dp[c] = max(dp[c], dp[c - price] + value);
                    }
                }

                k++;
            }
            for (int c = 0; c <= budget; c++) {
                if (cur[c] != NEG) {
                    ans = max(ans, cur[c] + (budget - c) / p);
                }
            }
        }

        return ans;
    }
};
