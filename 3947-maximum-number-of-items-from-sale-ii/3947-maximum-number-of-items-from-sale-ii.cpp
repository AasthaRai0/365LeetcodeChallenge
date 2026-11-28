class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n=items.size();
        vector<long long> cnt(n+1,0),g(n+1,0);
        long long m=LLONG_MAX,r=budget,ans=0;
        for(int i=0;i<n;i++){
            cnt[items[i][0]]++;
            m=min(m,(long long)items[i][1]);
        }
        for(int v=1;v<=n;v++){
            for(int k=v;k<=n;k+=v) g[v]+=cnt[k];
        }
        vector<pair<int,int>> a;
        for(int i=0;i<n;i++) a.push_back({items[i][1],items[i][0]});
        sort(a.begin(),a.end());
        for(int i=0;i<n;i++){
            long long p=a[i].first,x=g[a[i].second]-1;
            if(p>=2*m) break;
            long long t=min(x,r/p);
            r-=t*p;
            ans+=2*t;
            if(t<x) break;
        }
        return ans+r/m;
    }
};