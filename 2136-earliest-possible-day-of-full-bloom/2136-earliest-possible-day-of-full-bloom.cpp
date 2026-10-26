class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        int n = plantTime.size();
        vector<pair<int,int>>seeds;

        for(int i = 0; i < n; i++){
            seeds.push_back({growTime[i],plantTime[i]});
        }

        sort(seeds.rbegin(),seeds.rend());

        int start = 0;
        int ans = 0;
        
        for(int i = 0; i < n; i++){
            int a = seeds[i].first;
            int b = seeds[i].second;

            start += b;
            ans = max(ans,start + a);
        }
        return ans;
    }
};