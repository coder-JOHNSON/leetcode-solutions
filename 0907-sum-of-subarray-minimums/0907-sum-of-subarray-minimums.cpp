class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        stack<int>st1,st2;
        vector<int>p1(n),p2(n);

        for(int i = 0; i < n; i++){
            while(st1.size() > 0 && arr[st1.top()] >= arr[i]) st1.pop();
            if(st1.size() > 0) p1[i] = st1.top();
            else p1[i] = -1;
            st1.push(i);
        }

        for(int i = n - 1; i >= 0; i--){
            while(st2.size() > 0 && arr[st2.top()] > arr[i]) st2.pop();
            if(st2.size() > 0) p2[i] = st2.top();
            else p2[i] = n;
            st2.push(i);
        }

        long long fians = 0;
        int mod = 1e9 + 7;
        for(int i = 0; i < n; i++){
            long long ans = 1LL * arr[i] * (i - p1[i]) * (p2[i] - i);
            fians = (fians + ans) % mod;
        }
        return fians;
    }
};