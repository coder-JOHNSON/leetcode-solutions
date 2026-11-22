class Solution {
public:
    set<vector<int>> s;
    void getAllCombinations(vector<int>& arr,int idx,int tar,vector<vector<int>>& ans,vector<int>& comb){
        if(idx == arr.size() || tar < 0) return;

        if(tar == 0){
            if(s.find(comb) == s.end()){
                s.insert(comb);
                ans.push_back(comb);
            }
            return;
        }

        comb.push_back(arr[idx]);
        //single
        getAllCombinations(arr,idx + 1,tar - arr[idx],ans,comb);
        //multiple
        getAllCombinations(arr,idx,tar - arr[idx],ans,comb);
        comb.pop_back();
        //exclusion
        getAllCombinations(arr,idx + 1,tar,ans,comb);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> comb;
        getAllCombinations(candidates,0,target,ans,comb);
        return ans;
    }
};