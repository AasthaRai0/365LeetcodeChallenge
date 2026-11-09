
class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        
        int n = arrival.size();

        vector<int> cnt(k, 0);

        priority_queue<
            pair<int, int>,
            vector<pair<int, int>>,
            greater<pair<int, int>>
        > pq;

        set<int> st;

        for (int i = 0; i < k; i++) {
            st.insert(i);
        }

        for (int i = 0; i < n; i++) {

            int time = arrival[i];

            while (!pq.empty() && pq.top().first <= time) {

                int idx = pq.top().second;

                pq.pop();

                st.insert(idx);
            }
            if (st.empty()) {
                continue;
            }
            int preferred = i % k;

            auto it = st.lower_bound(preferred);

            int idx;

            if (it == st.end()) {
                idx = *st.begin();
            }
            else {
                idx = *it;
            }
            cnt[idx]++;
            pq.push({time + load[i], idx});
            st.erase(idx);
        }
        int mx = *max_element(cnt.begin(), cnt.end());
        vector<int> ans;
        for (int i = 0; i < k; i++) {
            if (cnt[i] == mx) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};
