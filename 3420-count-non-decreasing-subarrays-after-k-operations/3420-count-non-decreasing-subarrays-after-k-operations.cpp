
class Solution {
public:
    long long countNonDecreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> prefix(n + 1, 0);

        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + nums[i];
        }
        vector<int> nextGreater(n, n);
        stack<int> st;

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] <= nums[i]) {
                st.pop();
            }
            if (!st.empty()) {
                nextGreater[i] = st.top();
            }
            st.push(i);
        }
        vector<long long> fullCost(n);

        for (int i = 0; i < n; i++) {
            int next = nextGreater[i];
            fullCost[i] = 1LL * nums[i] * (next - i) - (prefix[next] - prefix[i]);
        }

        int LOG = 1;
        while ((1 << LOG) <= n) {
            LOG++;
        }

        vector<vector<int>> up(LOG, vector<int>(n + 1, n));
        vector<vector<long long>> cost(
            LOG, vector<long long>(n + 1, 0)
        );

        for (int i = 0; i < n; i++) {
            up[0][i] = nextGreater[i];
            cost[0][i] = fullCost[i];
        }

        for (int j = 1; j < LOG; j++) {
            for (int i = 0; i < n; i++) {
                int next = up[j - 1][i];
                up[j][i] = up[j - 1][next];
                cost[j][i] = cost[j - 1][i] + cost[j - 1][next];
            }
        }
        auto getCost = [&](int left, int right) {
            long long total = 0;
            int pos = left;

            for (int j = LOG - 1; j >= 0; j--) {
                if (up[j][pos] <= right) {
                    total += cost[j][pos];
                    pos = up[j][pos];
                }
            }
            total += 1LL * nums[pos] * (right - pos + 1) - (prefix[right + 1] - prefix[pos]);

            return total;
        };
        long long ans = 0;

        for (int right = 0; right < n; right++) {
            int left = 0;
            int high = right;

            while (left < high) {
                int mid = left + (high - left) / 2;

                if (getCost(mid, right) <= k) {
                    high = mid;
                } else {
                    left = mid + 1;
                }
            }

            ans += right - left + 1;
        }

        return ans;
    }
};
