class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int>st;

        for(int &a : asteroids){
            while(!st.empty() && a < 0 && st.top() > 0){
                int sum = a + st.top();

                if(sum < 0) st.pop();
                else if(sum > 0){
                    a = 0; // a zero mean it break while loop or we can write break directly
                }
                else{ // sum = 0
                    st.pop();
                    a = 0; // a zero mean it break while loop or we can write break directly
                }
            }
            if(a != 0) st.push(a);
        }

        int s = st.size();
        vector<int>result(s);
        int i = s - 1;

        while(!st.empty()){
            result[i] = st.top();
            st.pop();
            i--;
        }
        return result;
    }
};