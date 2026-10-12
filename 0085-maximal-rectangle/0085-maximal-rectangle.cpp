class Solution {
public:
    int largestRectangleArea(vector<int>& heights){
        int n = heights.size();
        vector<int>pse(n);
        vector<int>nse(n);
        stack<int>st;

        for(int i = 0; i < n; i++){
            while(!st.empty() && heights[i] <= heights[st.top()]) st.pop();
            if(st.size()) pse[i] = st.top();
            else pse[i] = -1;
            st.push(i);
        }

        while(!st.empty()) st.pop();

        for(int i = n - 1; i >= 0; i--){
            while(!st.empty() && heights[i] <= heights[st.top()]) st.pop();
            if(st.size()) nse[i] = st.top();
            else nse[i] = n;
            st.push(i);
        }

        int ans = 0;
        for(int i = 0; i < n; i++){
            int width = nse[i] - pse[i] - 1;
            int area = heights[i] * width;
            ans = max(ans,area);
        }
        return ans;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        int maxi = INT_MIN;
        vector<int> histogram(matrix[0].size());

        for(int i = 0; i < matrix.size(); i++){
            for(int j = 0; j < histogram.size(); j++){
                if(matrix[i][j] == '1') histogram[j]++;
                else histogram[j] = 0;
            }
            maxi = max(maxi,largestRectangleArea(histogram));
        }
        return maxi;
    }
};