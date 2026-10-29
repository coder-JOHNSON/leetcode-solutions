class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        if(n == 0) return {};

        set<int>unique(arr.begin(),arr.end());
        
        unordered_map<int,int> rankers;
        int rank = 1;

        for(const int &ele : unique){
            rankers[ele] = rank++;
        }

        vector<int>ans;
        for(int &ele : arr){
            ans.push_back(rankers[ele]);
        }
        return ans;
    }
};