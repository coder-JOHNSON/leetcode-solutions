class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        int n = nums.size();
        long long op = 0;
        int prev = nums[n - 1];

        for(int i = n - 2; i >= 0; i--){
            if(nums[i] <= prev){
                prev = nums[i];
            }
            else{
                int parts = nums[i] / prev;

                if(nums[i] % prev != 0) parts++;

                op = op + parts - 1;
                prev = nums[i] / parts;
            }
        }
        return op;
    }
};