class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        stack<int> st;
        int n = heights.size();
        vector<int>ans(n);

        for(int i = n - 1; i >= 0; i--){
            int count = 0;

            while(st.size() > 0 && st.top() < heights[i]){
                st.pop();
                count++;
           }

            if(st.size() != 0) count++;
            ans[i] = count;
            st.push(heights[i]);
        }
        return ans;
    }
};