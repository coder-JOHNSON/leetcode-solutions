class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.size() == 1) return true;
        int maxJump = nums[0];
        int n = nums.size();

        for(int i = 0; i < n && maxJump >= i; i++){
            if(maxJump >= n - 1) return true;
            maxJump = max(maxJump,nums[i] + i);
        }
        return false;
    }
};