class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int>st;
        int ans = 0;
        for(int i = 0; i < operations.size(); i++){
            if(operations[i] == "+"){
                    int first = st.top();
                    st.pop();

                    int second = st.top();
                    st.push(first);
                    ans += first + second;
                    st.push(first + second);
            }
            else if(operations[i] == "D"){
                ans += 2 * st.top();
                st.push(2 * st.top());
            }
            else if(operations[i] == "C"){
                ans -= st.top();
                st.pop();
            }
            else{
                ans += stoi(operations[i]);
                st.push(stoi(operations[i]));
            }
        }
        // int ans = 0;
        // while(!st.empty()){
        //     ans += st.top();
        //     st.pop();
        // }
        return ans;
    }
};