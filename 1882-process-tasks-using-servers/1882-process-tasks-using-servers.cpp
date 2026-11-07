class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        set<pair<int,int>> free;
        set<pair<long long,pair<int,int>>> busy;

        int n = servers.size();
        int m = tasks.size();

        for(int i = 0; i < n; i++) {
            free.insert({servers[i], i});
        }

        long long curr = 0;
        vector<int> ans(m);

        for(int i = 0; i < m; i++) {

            curr = max(curr, (long long)i);

            while(!busy.empty()) {
                auto it = *busy.begin();

                if(it.first <= curr) {
                    free.insert({it.second.first, it.second.second});
                    busy.erase(busy.begin());
                }
                else {
                    break;
                }
            }

            if(free.empty()) {
                curr = busy.begin()->first;

                while(!busy.empty() && busy.begin()->first <= curr) {
                    auto it = *busy.begin();

                    free.insert({it.second.first, it.second.second});
                    busy.erase(busy.begin());
                }
            }

            auto it = *free.begin();

            ans[i] = it.second;

            busy.insert({
                curr + tasks[i],
                {it.first, it.second}
            });

            free.erase(free.begin());
        }

        return ans;
    }
};