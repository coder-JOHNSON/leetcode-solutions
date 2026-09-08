class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int>ans(n);
        vector<int>sol(n);
        ans[0] = height[0];
        sol[n - 1] = height[n - 1];

        for(int i = 1; i < n; i++){
            ans[i] = max(height[i],ans[i - 1]);
        }

        for(int i = n - 2; i >= 0; i--){
            sol[i] = max(height[i],sol[i + 1]);
        }

        int total = 0;
        for(int i = 0; i < n; i++) total += min(sol[i],ans[i]) - height[i];
        return total;
    }
};