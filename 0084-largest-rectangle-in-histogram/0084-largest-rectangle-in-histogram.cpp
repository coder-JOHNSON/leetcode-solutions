class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int>pse(n);
        vector<int>nse(n);
        stack<int>st;

        for(int i = 0; i < heights.size(); i++){
            while(st.size() > 0 && heights[i] <= heights[st.top()]) st.pop();
            if(st.size() > 0) pse[i] = st.top();
            else pse[i] = -1;
            st.push(i);
        }

        while(!st.empty()) st.pop();

        for(int i = heights.size() - 1; i >= 0; i--){
            while(st.size() > 0 && heights[i] <= heights[st.top()]) st.pop();
            if(st.size() > 0) nse[i] = st.top();
            else nse[i] = n;
            st.push(i);
        }

        int ans = 0;
        for(int i = 0; i < heights.size(); i++){
            int width = nse[i] - pse[i] - 1;
            int area = heights[i] * width;
            ans = max(ans,area);
        }
        return ans;
    }
};